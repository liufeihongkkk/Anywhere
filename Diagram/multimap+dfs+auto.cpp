//
// Created by hp on 2/8/2021.
//
/*
 * 存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。

给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。

题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。

 这些相邻元素对可以 按任意顺序 出现。返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<int> t;  //t相当于标记数组
    vector<int> v;
    map<int,int> mp1;
    multimap<int,int> mp;
    multimap<int,int>::iterator m;
    void dfs(int d,int i){
        if(t.find(d)!=t.end()&&i!=0)
            return;
        v.push_back(d);
        t.insert(d);
        m=mp.find(d);
        for(;m!=mp.end();m++){
            int temp=m->second;
            if(t.find(temp)==t.end())
                dfs(temp,1);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        //1.将vector数组转为multimap
        for(auto& inner:adjacentPairs){
                mp1[inner[0]]++;
                mp1[inner[1]]++;
                mp.insert(pair<int,int>(inner[0],inner[1]));
                mp.insert(pair<int,int>(inner[1],inner[0]));
        }
        //2.dfs函数的书写
        for(auto &i:mp1)
            if(i.second==1){
                t.insert(i.first);
                int temp=i.first;
                dfs(temp,0);
                break;
            }
        return v;
    }
};
int main(){
    Solution s;
    vector<int> v;
    int m,k;
    cin>>m;
    vector<vector<int>> a(m);
    for(auto &i:a)
        i.resize(2);
    for(auto &inner:a){
        for(auto &i:inner){
            cin>>i;
        }
    }
    v=s.restoreArray(a);
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}

