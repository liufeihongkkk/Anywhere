//
// Created by hp on 2/7/2021.
//

/*
 */
#include <bits/stdc++.h>
using namespace std;
struct  box{
    int x,y;
    box(int x1,int y1):x(x1),y(y1){}
};
struct node{  //代表当前的高度
    int num; //可用于当前的和上面所有层的盒子总数
    vector<box> b; //当前高度的各个盒子
};
Tutorial:
加入第一维是高度i，第二维是保留到该层的盒子总数j，第三维是这一层利用的盒子总数k
//下一层的可以利用a[i-1][j]的这个值  a[i][j][k]|=a[i+1][j-k][s]  //s是<=j-k的 (剪枝: 一遇到true就返回:if语句)
关于初始值？    //但上层的还是依赖于下层的: return func() 还是要递归!
func书写问题
    函数参数的设置: 向上层传递下层的设置好的结点信息
    1.第一次传给func的值: 高度i、保留到该层的盒子总数j、node(下一层的结点信息)
    2.递归终止条件: 保留到该层的盒子总数为0(能到这一层说明为true,故返回true)
    3.不能传递到下一层的情况：
class Solution {
public:
    int num;
    int minimumBoxes(int n) {
        num=n;
        //盒子肯定是尽可能紧凑排放的
        //对是否能放置盒子的判断
        //数据结构、算法的选择,递归+动态规划
        //盒子肯定是尽可能按照四个角的方向进行排放的
          //是否是一个贪心的问题: 有一部分是
        1.线段树的每个结点是对应z值(如何对结点进行定义)
        2.第一层盒子的摆放原则？ 肯定尽量往墙角放(solved)
    }
};
int main(){
    Solution s;
    int x;
    cin>>x;
    cout<<s.minimumBoxes(x);
    return 0;
}