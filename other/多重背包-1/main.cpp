/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-27-09.43
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


// Time complexity: N*W*max(ci)
const int MAXN=100,MAXW=50010;
LL dp[MAXN][MAXW];
struct node
{
      int wi,pi,ci;
} wu[MAXN];

int n,m;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d %d",&n,&m))
      {
            for(int i=1;i<=n;++i)
                  scanf("%d %d %d",&wu[i].wi,&wu[i].pi,&wu[i].ci);
            for(int i=0;i<=m;++i)
                  dp[0][i]=0;
            for(int i=1;i<=n;++i)
            {
                  for(int j=0;j<=m;++j)
                  {
                        int up=min(j/wu[i].wi,wu[i].ci);
                        int maxx=0;
                        for(int k=0;k<=up;++k)
                        {
                              maxx=max(maxx,dp[i-1][j-k*wu[i].wi]+k*wu[i].pi);
                        }
                        dp[i][j]=maxx;
                  }
            }
            printf("%I64d\n",dp[n][m]);
      }
      return 0;
}
/*

*/
