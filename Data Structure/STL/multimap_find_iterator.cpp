//
// Created by hp on 2/9/2021.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int  k;
    multimap<string, int > mp;
    mp.insert(pair<string,int>("中国",5));
    mp.insert(pair<string,int>("中国",6));
    mp.insert(pair<string,int>("中国",7));
    mp.insert(pair<string,int>("中国",8));
    multimap<string, int >::iterator m;
    m = mp.find("中国");
    for (k = 0;k != mp.count("中国");k++,m++)
        cout<<m->first<< "--" <<m->second<<endl;
    return 0;
}