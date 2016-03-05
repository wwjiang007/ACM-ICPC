/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-05-10.39
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

vector<double> divide_table;
void wechat_money_divide(double money,int n)
{
    money*=100;
    for(int i=0;i<n;++i)
    {
        int rest_people=n-i-1;
        int max_money=money-10*rest_people; // 剩下的人至少保证每人1分钱
        double ave=max_money/rest_people;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    double money;
    int n;
    while(cin>>money>>n)
    {
        wechat_money_divide(money,n);
        cout<<"---------------"<<endl;
        double sum=0.;
        for(auto p:divide_table)
        {
            printf("%.2f\n",p);
            sum+=p;
        }
        cout<<"sum="<<sum<<endl;
        cout<<"---------------"<<endl;
    }
    return 0;
}
/*

*/
