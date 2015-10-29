/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2013-10-28-17.43
* Time: 0MS
* Memory: 137KB
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int N=110;
const int M=10010;
int w[N],v[N],dp[M];
int n,m;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(cin>>n>>m)
      {
            for(int i=1;i<=n;++i)
                  cin>>w[i]>>v[i];
            for(int i=0;i<=m;++i)
                  dp[i]=0;
            for(int i=1;i<=n;++i)
            {
                  for(int j=m;j>=0;--j)
                  {
                        if(j-w[i]<0)
                              continue;
                        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                  }
            }
            printf("%d\n",dp[m]);
      }
      return 0;
}
/*

*/
