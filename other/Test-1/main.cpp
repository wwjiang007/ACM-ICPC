/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-04-18.01
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
int n;
vector<int> pr;
vector<int> in;
int main()
{
      while(cin>>n)
      {
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  pr.push_back(tmp);
            }
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  in.push_back(tmp);
            }
            getPostOrder(0,0,);
      }
      return 0;
}
