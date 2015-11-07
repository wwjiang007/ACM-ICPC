#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <assert.h>
#include <set>
#include <ctype.h>
#define ll long long
#define max3(a,b,c) max(a,max(b,c))

using namespace std;

double dp[110][110];

int main()
{
      int t;
      cin>>t;
      int cas=0;
      while(t--)
      {
            cas++;
            int a,b;
            char c;
            double p;
            cin>>a>>c>>b;
            p=(double)a/b;
            int n;
            cin>>n;
            //init
            for(int i=0; i<=n; i++)
                  for(int j=0; j<=n; j++)dp[i][j]=0.0;

            dp[1][0]=1.0-p;
            for(int i=2; i<=n; i++)
            {
                  for(int j=0; j<=n; j++)
                  {
                        dp[i][j]+=dp[i-1][j]*(1.0-p);
                        if((j+1)*b>a*i)break;
                        dp[i][j+1]=dp[i-1][j]*p;
                  }
            }

            double plose=0.0;
            for(int i=0; i<=n; i++)
            {
                  plose+=dp[n][i];
            }
            printf("Case #%d: %d\n",cas,(int)(1.0/plose));
      }
      return 0;
}
