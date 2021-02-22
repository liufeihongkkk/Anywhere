//
// Created by clay on 2021/2/20.
//
/*
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string t="";
        //递归的思想对两个字符串进行比较： 后面的字符串是否大于当前的
        if(word1.size()==1&&word2.size()!=1){
            //insert into word2
            return max(word1[0]+word2,word2[0]+largestMerge(word1,word2.substr(1)));
        }
        else if(word2.size()==1&&word1.size()!=1)
            return largestMerge(word2,word1);
        else if(word2.size()==1&&word1.size()==1){
            string str="",str2="";
            str+=word2[0];
            str2+=word1[0];
            str=word1[0]>word2[0]?(str2+word2[0]):(str+word1[0]);
            return str;
        }
        if(word1[0]!=word2[0])
            t=word1[0]>word2[0]?(word1[0]+largestMerge(word1.substr(1),word2)):(word2[0]+largestMerge(word1,word2.substr(1)));
        else{
            int x=word1.find_first_not_of(word1[0]);
            int y=word2.find_first_not_of(word2[0]);
            if(x!=-1&&y!=-1)
                t= max(word1.substr(0,x)+largestMerge(word1.substr(x), word2), word2.substr(0,y)+largestMerge(word1, word2.substr(y)));
            else if(y==-1&&x!=-1)
                t= max(word2+word1,word1.substr(0,x)+largestMerge(word1.substr(x), word2));
            else if(y!=-1&&x==-1)
                t =max(word1+word2,word2.substr(0,y)+largestMerge(word1, word2.substr(y)));
            else{
                t+=word2;
                t+=word1;
            }
        }
        return t;
    }
};
int main(){
    Solution s;
    string t1,t2;
    cin>>t1>>t2;
    cout<<s.largestMerge(t1,t2);
    return 0;
}