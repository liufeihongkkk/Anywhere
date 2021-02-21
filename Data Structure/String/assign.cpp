//
// Created by hp on 2/16/2021.
//
/*给你一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。

如果nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。

源数组中可能存在 重复项 。

注意：我们称数组 A 在轮转 x 个位置后得到长度相同的数组 B ，当它们满足 A[i] == B[(i+x) % A.length] ，其中 % 为取余运算。
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is(string t){
        int num=0;
        for(auto &s:t){
            if(num!=0&&s<t[num-1])
                return false;
            num++;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        for(auto &t:nums)
            t+='0';
        string str;
        str.assign(nums.begin(),nums.end());
        int num=0;
        for(auto &t:str){
            string sub;
            if(num!=nums.size()-1){
                sub=str.substr(num+1);
                sub+=(str.substr(0,num+1));
            }
            else
                sub=str;
            if(is(sub))
                return true;
            num++;
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> x;
    int y;
    cin>>y;
    x.resize(y);
    for(auto &t:x)
        cin>>t;
    cout<<boolalpha<<s.check(x);
    return 0;
}
