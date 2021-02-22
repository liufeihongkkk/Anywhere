//
// Created by hp on 2/6/2021.
//

#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
class Solution {
public:
    int kthLargestValue(vector<vector<int> >& matrix, int k) {
        list<int> lis;
        dp[0][0]=matrix[0][0];
        lis.push_back(dp[0][0]);
        for(int i=0;i<matrix.size();i++){
            int t=matrix[i][0];
            if(i!=0){
                dp[i][0]=t^dp[i-1][0];
                lis.push_back(dp[i][0]);
            }
            for(int j=1;j<matrix[0].size();j++){
                t^=matrix[i][j];
                if(i==0){
                    dp[i][j]=t;
                    lis.push_back(dp[i][j]);
                    continue;
                }
                dp[i][j]=t^dp[i-1][j];
                lis.push_back(dp[i][j]);
            }
        }
        lis.sort();
        list<int>::iterator it = lis.begin();
        advance(it,lis.size()-k);
        return *it;
    }
};