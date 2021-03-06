/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-20-15.06
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

const int MAXN=100010;
char s1[MAXN],s2[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%s%s",s1,s2);
            int gap=strlen(s2)-strlen(s1);
            if(gap<0){ puts("No"); continue; }
            int cnt=0;
            bool flag=true,tot=true;
            for(int i=0,j=0;i<=strlen(s2);++i,++j)
            {
                  if(s2[i]!=s2[0]) tot=false;
                  if(s2[i]!=s1[j])
                  {
                        if(s2[i]!=s2[i-1]&&i) ++cnt,--j;
                        else {if(i==0 || tot) {flag=false; break;} else ++cnt,--j;}
                  }
            }
            if(cnt!=gap) flag=false;
            if(flag) puts("Yes");
            else puts("No");
      }
      return 0;
}
/*

*/
