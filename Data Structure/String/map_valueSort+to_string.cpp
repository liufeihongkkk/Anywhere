//
// Created by hp on 2/7/2021.
//
/*
 * 你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和highLimit ，
 * 即n == highLimit - lowLimit + 1）。另有无限数量的盒子，编号从 1 到 infinity 。
你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，
 而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。

给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。
 * */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> MP;
    struct cmp{
        bool operator()(const MP& mp1,const MP& mp2){
            return mp1.second < mp2.second;
        }
    };
    int countBalls(int lowLimit, int highLimit) {
        map <int,int>mp;
        for(int i=lowLimit;i<=highLimit;i++){
            int sum=0;
            string t=to_string(i);
            for(int j=0;j<t.size();j++){
                sum+=t[j]-'0';
            }
            mp[sum]++;
        }
        vector<MP> pa(mp.begin(),mp.end());
        sort(pa.begin(),pa.end(),cmp());
        return pa.rbegin()->second;
    }
};