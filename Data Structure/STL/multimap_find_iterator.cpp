//
// Created by hp on 2/9/2021.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int  k;
    multimap<string, int > mp;
    mp.insert(pair<string,int>("�й�",5));
    mp.insert(pair<string,int>("�й�",6));
    mp.insert(pair<string,int>("�й�",7));
    mp.insert(pair<string,int>("�й�",8));
    multimap<string, int >::iterator m;
    m = mp.find("�й�");
    for (k = 0;k != mp.count("�й�");k++,m++)
        cout<<m->first<< "--" <<m->second<<endl;
    return 0;
}