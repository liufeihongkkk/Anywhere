//
// Created by hp on 2/9/2021.
//
/*已知n个建筑的坐标(x,y)和高度，查询点(x,y)的左下角中高度第k小的建筑的高度。
解题思路：坐标加高度相当于是一个三维的题目。首先要发现这里的k非常小，
 所以我们只要用线段树维护区间内最小的10个建筑的高度。现将查询与建筑一起离散化处理，采用巧妙的降维方式，
 将x、y、flag(是否为建筑)的优先级排序，y作为线段树下标。对于建筑只要进行单点更新操作即可，
 查询操作是一个区间[1,pos]的查询。
 * */

#include <bits/stdc++.h>
using namespace std;
#define N 30005

struct node
{
    int x,y,k,flag,id;
    bool operator < (const node &rhs)const
    {
        if(x != rhs.x)  return x < rhs.x;
        if(y != rhs.y)  return y < rhs.y;
        return flag < rhs.flag;
    }
}s[N*2];  //为什么不是4N
int a[N*2];
struct tree
{
    int l,r,sum;  //这里的sum值的含义是当前l到r范围内的相同y结点的x的数量
    int num[23];  //记录区间最值
}tree[N*8];
void build(int o,int l,int r)
{
    tree[o].l = l;
    tree[o].r = r;
    tree[o].sum = 0; //是因为不需要求区间和吗，这里的sum都为0
    if(l == r)  return;
    int m = (l+r)/2;
    build(2*o,l,m);
    build(2*o+1,m+1,r);
}
void del(int o)//只记录一个区间的10个最小值   //对应合并后的排序和筛选工作
{
    sort(tree[o].num,tree[o].num+tree[o].sum);   //排序过后，最后一个值肯定是最小的值
    if(tree[o].sum > 10)    tree[o].sum = 10;  //相同结点多了的话就不进行记录
}
void pushup(int o)
{
    int i;
    int k = 0;
    for(i = 0; i < tree[2*o].sum; i++)   //两两合并到上一层区间
        tree[o].num[k++] = tree[2*o].num[i];
    for(i = 0; i < tree[2*o+1].sum; i++)  //先合并左孩子，后合并右孩子
        tree[o].num[k++] = tree[2*o+1].num[i];
    tree[o].sum = k;  //最后k的值作为当前结点的数量
    del(o);
}
void update(int o,int pos,int k)    //build和update为什么要分开
{
    if(tree[o].l == tree[o].r)
    {
        tree[o].num[tree[o].sum++] = k;
        del(o);
        return;
    }
    int m = (tree[o].l+tree[o].r)/2;   //注意：线段树是有一个二分处理的过程，所以[1,pos]是分为了[1,m]和[m,pos]
    if(pos <= m)    update(2*o,pos,k);
    else update(2*o+1,pos,k);
    pushup(o);
}
int path[25],sz;
void query(int o,int x,int y)
{
    if(x <= tree[o].l && tree[o].r <= y)  //根节点的num是将所有的x和y放在一起看的，所有的子区间都是左孩子，没有右孩子
    {
        for(int i = 0; i < tree[o].sum; i++)
            path[sz++] = tree[o].num[i];
        sort(path,path+sz);
        if(sz > 10) sz = 10;
        return;
    }
    int m = (tree[o].l + tree[o].r)/2;
    if(x <= m)  query(2*o,x,y);    //左孩子肯定优先考虑，因为左孩子的x和y值一定比右孩子都要小
    if(y > m)   query(2*o+1,x,y);
}
int ans[N*2];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        int i,tot = 0;
        for(i = 0; i < n+m; i++)
        {
            scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].k);  //这里的k为高度
            if(i < n)   s[i].flag = 0;
            else s[i].flag = 1;
            s[i].id = i;     //为什么要设置id号？
            a[tot++] = s[i].y;  //存储每一位的y
        }
        sort(s,s+n+m);  //注意这里将查询结点和固有结点放在一起排序了，那么查询节点对应下标之前的下标一定是比它的x和y下标要小的
        sort(a,a+tot);//将y坐标离散化处理
        tot = unique(a,a+tot) - a;  //直接用list实现即可
        build(1,1,tot);

        for(i = 0; i < n+m; i++)
        {
            int pos = lower_bound(a,a+tot,s[i].y) - a + 1;  //因为从1开始计数的，所以pos要+1，肯定能找到，其实用list.find即可   //返回第一个大于或等于被查数的值的下标(从1开始)
            if(s[i].flag == 0)
            {
                update(1,pos,s[i].k);   //是从根结点1开始，逐层下降找到pos对应的结点，并更新
            }
            else
            {
                sz = 0;
                query(1,1,pos);  //从y为1开始，到pos(y对应1的位置不一定就有结点，但范围之内肯定有的)
                if(sz < s[i].k) ans[ s[i].id ] = -1;  //不存在则返回-1，sz记录当前只有第几小
                else ans[ s[i].id ] = path[ s[i].k-1 ];  //s[i].k是当前第k小
            }
        }
        for(i = n; i < n+m; i++) {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
/*
5 3
1 1 2
2 2 3
2 4 4
3 1 6
4 4 1
2 3 2
1 1 1
4 4 1
*/