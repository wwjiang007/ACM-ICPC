/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-14-22.40
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int Cas;
      cin>>Cas;
      while(Cas--)
      {
            int n,x,y,z;
            int a,b,c,get;
            cin>>n>>x>>y>>z;
            a=b=c=n;
            LL ans=n;
            while(a>=x || b>=y || c>=z)
            {
                  ans+=a/x+b/y+c/z;
                  get=a/x+b/y+c/z;
                  a=(a%x)+get;
                  b=(b%y)+get;
                  c=(c%z)+get;
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
