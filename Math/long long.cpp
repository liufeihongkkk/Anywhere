//
// Created by hp on 2/13/2021.
//

/*给你一个下标从 0 开始的正整数数组candiesCount，其中candiesCount[i]表示你拥有的第i类糖果的数目。同时给你一个二维数组 queries ，其中 queries[i] = [favoriteTypei, favoriteDayi, dailyCapi] 。

你按照如下规则进行一场游戏：

你从第0天开始吃糖果。
你在吃完 所有第 i - 1类糖果之前，不能吃任何一颗第 i类糖果。
在吃完所有糖果之前，你必须每天 至少吃 一颗糖果。
请你构建一个布尔型数组answer，满足answer.length == queries.length 。answer[i]为true的条件是：在每天吃 不超过 dailyCapi颗糖果的前提下，
 你可以在第favoriteDayi天吃到第favoriteTypei类糖果；否则 answer[i]为 false。注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。

请你返回得到的数组answer。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<bool> v;
    vector<ll> s; //下标从1开始
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        //统计区间和
        int num=0;s.push_back(0);
        for(auto &i:candiesCount){
            s.push_back(s[num]+i);
            num++;
        }
        for(auto &i:queries){
            //边界情况的排除: 至少吃一颗和每天都吃dailyCap颗都会吃不到(一个越界了一个达不到)
            //剩下的情况一定能吃到吗？-肯定能
            ll sum=(ll)(i[1]+1)*i[2];
            if((i[1]+1)>s[i[0]+1]||sum<=s[i[0]]){
                v.push_back(false);
                continue;
            }
            v.push_back(true);
        }
        return v;
    }
};
//int main(){
//    Solution s;
//    int t,m,n;
//    cin>>t;
//    vector<int> c(t);
//
//    for(auto &i:c)
//        cin>>i;
//    vector<bool> v;
//    cin>>m;
//    vector<vector<int>> vec(m);
//    for(auto &inner:vec)
//        inner.resize(3);
//    for(auto &inner:vec)
//        for(auto &i:inner)
//            cin>>i;
//    v=s.canEat(c,vec);
//    for(auto i:v)
//        cout<<boolalpha<<i<<" ";
//    return 0;
//}