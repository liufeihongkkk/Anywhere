//
// Created by hp on 2/14/2021.
//

/*给你一个字符串s，如果可以将它分割成三个非空回文子字符串，那么返回true，否则返回false。

当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。

 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> mp,mp2,mp3,mp4;
    bool indeed(vector<vector<int>> &t){
        auto i=t.begin();
        auto j=t.rbegin();
        int num=0;
        for(;num!=t.size()/2;i++,j++)
            if((*i)[0]!=(*j)[0]||(*i)[1]!=(*j)[1])
                return false;
            else
                num++;
            return true;
    }
    void del(vector<vector<int>> &t,int pos,int k){
        for(int i=pos;i<t.size();i++)
            t[i][2]=t[i][2]-k;
    }
    bool divide(int i,vector<vector<int>> &mp2,vector<vector<int>> &mp3){
        int pos,num=0; //需要修改的下标
        //前面分隔到的map(找到第一个大于或等于的下标)
        for(auto &t:mp2){
            if(i+1<=t[2]){
                pos=num;
                break;
            }
            else
                num++;
        }
        //分割前面的部分
        if(pos==0){
            mp3[pos][2]=mp2[pos][1]-i-1;
            mp3[pos][1]=mp3[pos][2];
            del(mp3,pos+1,i+1);
            if(mp3[pos][1]==0)
                mp3.erase(mp3.begin());
        } //pos等于0前面一部分一定是回文数
        else{
            mp2[pos][1]=i+1-mp2[pos-1][2];
            mp2[pos][2]=i+1;
            auto it=mp2.begin();
            advance(it,pos+1);
            mp2.erase(it,mp2.end());
            if(!indeed(mp2))   //mp2后面的直接删掉了，不用考虑前缀和
                return false;
            mp3[pos][1]=mp3[pos][1]-mp2[pos][1];
            mp3[pos][2]=mp3[pos][1];
            del(mp3,pos+1,i+1);
            auto it2=mp3.begin();
            advance(it2,pos);
            mp3.erase(mp3.begin(),it2); //左闭右开的删除
            if(mp3[0][1]==0)
                mp3.erase(mp3.begin());
        }
        return true;
    }
    bool indeed(string t){
        for(int i=0;i<t.size()/2;i++)
            if(t[i]!=t[t.size()-i-1])
                return false;
        return true;
    }
    bool check(string s) {
        ios::sync_with_stdio(false);
        //1.确定第一个串大小
        //2.分割剩余大小，并分别判断是不是回文串
        for(int i=0;i<s.size()-2;i++){
            if(!indeed(s.substr(0,i+1)))
                continue;
            string t=s.substr(i+1);
            for(int j=0;j<t.size()-1;j++)
                if(!indeed(t.substr(0,j+1))||!indeed(t.substr(j+1)))
                    continue;
                else
                    return true;
        }
        return false;
    }
    bool checkPartitioning(string s) {
        //1.将串转为二维vector
        int num=0; //记录总个数为num+1
        int snum=s.size(); //记录字母个数
        string t=s;
        mp.resize(snum);

        while(s.size()!=0){
            mp[num].push_back(s[0]);
            int t=s.find_first_not_of(s[0]);
            if(t!=-1){
                mp[num].push_back(t);
                //在赋值过程中计算前缀和
                if(num==0)
                    mp[num].push_back(t);
                else{
                    mp[num].push_back(t+mp[num-1][2]);
                }
                s=s.substr(t);
                num++;
            }
            else{
                mp[num].push_back(s.size());
                if(num==0)
                    mp[num].push_back(s.size());
                else{
                    mp[num].push_back(s.size()+mp[num-1][2]);
                }
                break;
            }
        }
        mp.resize(num+1);  //去除后面的多余元素
        if(num+1>=snum/2)
            if(check(t))
                return true;
            else
                return false;
        //2.确定第一个串大小
        //3.分割剩余大小，并分别判断是不是回文串
        for(int i=0;i<snum-2;i++){
            //每次都要重新拷贝两份map
            mp2=mp;
            mp3=mp;
            if(!divide(i,mp2,mp3))
                continue;

            //后面分隔到的map
            for(int j=0;j<snum-i-1;j++){
                mp2=mp3; //使用mp2节省空间
                mp4=mp3;
                if(!divide(j,mp2,mp4))
                    continue;
                if(!indeed(mp4))
                    continue;
                else
                    return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    string t;
    cin>>t;
    cout<<boolalpha<<s.checkPartitioning(t);
    return 0;
}