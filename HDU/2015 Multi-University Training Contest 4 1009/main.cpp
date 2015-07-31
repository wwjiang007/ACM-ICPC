/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-31-18.39
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

long long quickPower(long long a,long long b,long long m)
{
      long long tmp=1;
      while(b)
      {
            if(b&1) { tmp=(tmp*a)%m,b--; }
            b/=2,a=a*a%m;
      }
      return tmp;
}

int n,m;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(cin>>m>>n)
      {
            LL tmp=0;
            for(int i=1;i<=m;++i)
            {
                  tmp+=quickPower(i,n,1000000000);
            }
            int ans=0,t;
            while(tmp)
            {
                  t=tmp%10;
                  tmp/=10;
                  if(t==0) ans++;
                  else break;
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
