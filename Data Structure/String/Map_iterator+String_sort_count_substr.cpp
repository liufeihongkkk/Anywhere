//
// Created by hp on 1/30/2021.
//
/*���������ַ��� a �� b �����߾���Сд��ĸ��ɡ�һ�������У�����Խ� a �� b �е� ��һ�ַ� �ı�Ϊ ��һСд��ĸ ��
����������Ŀ�������������������� ֮һ ��

a �е� ÿ����ĸ ����ĸ���� �ϸ�С�� b �е� ÿ����ĸ ��
b �е� ÿ����ĸ ����ĸ���� �ϸ�С�� a �е� ÿ����ĸ ��
a �� b �� �� ͬһ�� ��ĸ��ɡ�
���ش��Ŀ������� ���� ��������
ʾ�� 1��

���룺a = "aba", b = "caa"
�����2
���ͣ�����ÿ����������ѷ����ֱ��ǣ�
1) �� b ��Ϊ "ccc"��2 �β��������� a �е�ÿ����ĸ��С�� b �е�ÿ����ĸ��
2) �� a ��Ϊ "bbb" ���� b ��Ϊ "aaa"��3 �β��������� b �е�ÿ����ĸ��С�� a �е�ÿ����ĸ��
3) �� a ��Ϊ "aaa" ���� b ��Ϊ "aaa"��2 �β��������� a �� b ��ͬһ����ĸ��ɡ�
��ѵķ���ֻ��Ҫ 2 �β������������� 1 �������� 3����
ʾ�� 2��

���룺a = "dabadd", b = "cda"
�����3
���ͣ��������� 1 ����ѷ����ǽ� b ��Ϊ "eee" ��
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
        //1.�ҵ�a��b�е�������С��ĸ����С��ĸ
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        min=a[0],max=a.back();
        min1=b[0],max1=b.back();
        int x2=a.size();
        int x3=b.size();
        int x1=x2>x3?x3:x2;
        int x4=x2<x3?x3:x2;
        //��stringתΪmap
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
        //2.a��b�Ƿ���ͬһ��ĸ��ɻ���ȫ����������
        if(eq()||min>max1||min1>max)
            return 0;
        //3.����a���ж�����ĸ���ڻ����b����С��ĸ
        int t1;
        if(min==max1){   //ֻ��һ��Ԫ�ؽ�������
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
        else{  //�����м佻��Ĳ���
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
                //��������м��������
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