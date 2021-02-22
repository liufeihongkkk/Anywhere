//
// Created by hp on 2/17/2021.
//

/*
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0,j=0;
        string t="";
        for(;i<word1.size()||j<word2.size();){
//            cout<<i<<" "<<j<<endl<<t<<endl;
            if(i==word1.size()&&j!=word2.size()){
                t+=word2.substr(j);
                break;
            }
            else if(i!=word1.size()&&j==word2.size()){
                t+=word1.substr(i);
                break;
            }
            if(word2[j]>word1[i]){
                t+=word2[j];
                j++;
            }
            else if(word2[j]==word1[i]){
                int x=word1.find_first_not_of(word2[j],i);
                int y=word2.find_first_not_of(word2[j],j);
                if(y==-1&&x!=-1){
                    if(word1[x]>word2[j]){
                        t+=word1.substr(i,x-i+1);
                        i+=x-i+1;
                    }
                    else{
                        t+=word2.substr(j);
                        t+=word1.substr(i,x-i+1);
                        j=word2.size();
                        i+=x-i+1;
                    }
                }
                else if(y!=-1&&x==-1){
                    if(word2[y]>word2[j]){
                        t+=word2.substr(j,y-j+1);
                        j+=y-j+1;
                    }
                    else{
                        t+=word1.substr(i);
                        t+=word2.substr(j,y-j+1);
                        i=word1.size();
                        j+=y-j+1;
                    }
                }
                else if(y==-1&&x==-1){
                    t+=word1.substr(i);
                    t+=word2.substr(j);
                    break;
                }
                else{
                    if(word1[x]==word2[y]||(word1[x]<word2[j]&&word2[y]<word2[j])){   //后续的字符又相等的情况处理
                        if(word1[x]>word2[j]){
                            if(x-i>y-j){
                                t+=word2.substr(j,y-j+1);
                                j+=y-j+1;
                            }
                            else if(x-i<y-j){
                                t+=word1.substr(i,x-i+1);
                                i+=x-i+1;
                            }
                            else{   //万一长度又相等了怎么办？
                                //indirect store the data
                                int m=word1[x];
                                while(x!=word1.size()&&word1[x]==word2[y]&&word1[x]>=m){
                                    x++;
                                    y++;
                                }
                                if(x==word1.size()){
                                    t+=word1.substr(i);
                                    t+=word1.substr(i);
                                    return t;
                                }
                                else if(word1[x]<m&&word2[y]<m){
                                    //递归的思想对两个字符串进行比较： 后面的字符串是否大于当前的
                                    t+=word1.substr(i,x-i);
                                    string t1=word1.substr(x);
                                    string t2=word2.substr(j);
                                    string t3=word1.substr(i);
                                    string t4=word2.substr(y);
                                    t+=max(largestMerge(t1,t2),largestMerge(t3,t4));
                                    return t;
                                }
                                else{  //must there is a bigger and there is a smaller.
                                    if(word1[x]>word2[y]){
                                        t+=word1.substr(i,x-i+1);
                                        i+=x-i+1;
                                    }
                                    else{
                                        t+=word2.substr(j,y-j+1);
                                        j+=y-j+1;
                                    }
                                }
                            }
                        }
                        else{
                            t+=word2.substr(j,y-j);
                            t+=word1.substr(i,x-i);
                            j+=y-j;
                            i+=x-i;
                        }
                    }
                    else if(word1[x]>word2[j]&&word1[x]>word2[y]){  //x大于y的情况
                        t+=word1.substr(i,x-i+1);
                        i+=x-i+1;
                    }
                    else if(word2[y]>word2[j]&&word1[x]<word2[y]){    //y大于x的情况
                        t+=word2.substr(j,y-j+1);
                        j+=y-j+1;
                    }
                    else
                }
            }
            else{
                t+=word1[i];
                i++;
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