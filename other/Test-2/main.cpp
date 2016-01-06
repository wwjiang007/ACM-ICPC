/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-06-19.00
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


class Solution
{
public:
    void wiggleSort(vector<int>& nums)
    {
          if(nums.size()<2) return ;
          for(int i=1;i<nums.size();++i)
          {
                if(( (i%2==1) && (nums[i]<nums[i-1]) )||( (i%2==0) && (nums[i]>nums[i-1]) ))
                  swap(nums[i],nums[i-1]);
          }
    }
};

int main()
{
      int n;
      while(cin>>n)
      {
            vector<int> ve;
            for(int i=0;i<n;++i)
            {
                  int tmp;
                  cin>>tmp;
                  ve.push_back(tmp);
            }
            Solution so;
            so.wiggleSort(ve);
            for(auto p:ve)
                  cout<<p<<" ";
            cout<<endl;
      }
    return 0;
}
