//
// Created by hp on 1/30/2021.
//
/*给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。
操作的最终目标是满足下列三个条件 之一 ：

a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
a 和 b 都 由 同一个 字母组成。
返回达成目标所需的 最少 操作数。
示例 1：

输入：a = "aba", b = "caa"
输出：2
解释：满足每个条件的最佳方案分别是：
1) 将 b 变为 "ccc"，2 次操作，满足 a 中的每个字母都小于 b 中的每个字母；
2) 将 a 变为 "bbb" 并将 b 变为 "aaa"，3 次操作，满足 b 中的每个字母都小于 a 中的每个字母；
3) 将 a 变为 "aaa" 并将 b 变为 "aaa"，2 次操作，满足 a 和 b 由同一个字母组成。
最佳的方案只需要 2 次操作（满足条件 1 或者条件 3）。
示例 2：

输入：a = "dabadd", b = "cda"
输出：3
解释：满足条件 1 的最佳方案是将 b 变为 "eee" 。
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int min,max,min1,max1;
    map<char, int> mp1;map<char, int> mp2;
    Solution(){}
    bool eq() {
        if (mp1.size()==mp2.size()&&mp1.size()==1&&mp1.begin()->first==mp2.begin()->first){
            return true;
        }
            return false;
    }
    int countLaL(map<char,int>t,char x){
        int c=0;
        for(map<char, int>::iterator iter = t.begin();iter!=t.end();iter++){
            if(iter->first<x)
                c+=iter->second;
        }
        return c;
    }
    int minCharacters(string a, string b) {
        std::ios::sync_with_stdio(false);
        //1.找到a、b中的最大和最小字母和最小字母
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        min=a[0],max=a.back();
        min1=b[0],max1=b.back();
        int x2=a.size();
        int x3=b.size();
        int x1=x2>x3?x3:x2;
        int x4=x2<x3?x3:x2;
        //将string转为map
        while(a.size()){
            int x=count(a.begin(), a.end(), a[0]);
            mp1[a[0]]+=x;
            a=a.substr(x);
        }
        while(b.size()){
            int x=count(b.begin(), b.end(), b[0]);
            mp2[b[0]]+=count(b.begin(), b.end(), b[0]);
            b=b.substr(x);
        }
        //2.a和b是否由同一字母组成或完全不交叉的情况
        if(eq()||min>max1||min1>max)
            return 0;
        //3.查找a中有多少字母大于或等于b的最小字母
        int t1;
        if(min==max1){   //只有一个元素交叉的情况
            int t=x2+x3-mp1[min]-mp2[min];
            if(min=='z')
                t1=mp2[min];
            else if(min=='a')
                t1=mp1[min];
            else
                t1=mp1[min]>mp2[min]?mp2[min]:mp1[min];
            return t1>t?t:t1;
        }
        else if(min1==max){
            int t=x2+x3-mp1[min1]-mp2[min1];
            if(min1=='a')
                t1=mp2[min1];
            else if(min1=='z')
                t1=mp1[min1];
            else
                t1=mp1[min1]>mp2[min1]?mp2[min1]:mp1[min1];
            return t1>t?t:t1;
        }
        else{  //考虑中间交叉的部分
            int cnt=0;
            int minValue;
            if(min=='a'&&max=='z'||min1=='a'&&max1=='z')
                minValue=x4;
            else
                minValue=x1;
            int i=0;
            for(map<char, int>::iterator iter = mp1.begin();iter!=mp1.end();iter++){
                int x=iter->first;
                int num1=iter->second;
                int num2=mp2[x];
                int minV;
                int sum=x2+x3-num1-num2;
                if(num2>0){
                    if(num1>num2){
                        minV=num2;
                    }
                    else
                        minV=num1;
                }
                else
                    minV=0;
                int c1=countLaL(mp2,x);
                //计算出比中间数大的数
                int c2=x3-num2-c1;
                int k2=x2-i-num1;
                if(x=='a')
                    minV=k2+num2>num1+c2?num1+c2:k2+num2;
                else if(x=='z'){
                    minV=i+num2>num1+c1?num1+c1:i+num2;
                }
                else
                    minV+=i+c2>c1+k2?c1+k2:i+c2;
                minV=minV>sum?sum:minV;
                i+=num1;
                if(minV<minValue)
                    minValue=minV;
            }
            return minValue;
        }
    }
};