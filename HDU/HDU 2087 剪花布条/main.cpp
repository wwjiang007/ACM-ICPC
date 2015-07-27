/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-16.18
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
char p[1010],t[1010];
int Next[1010];
void getNext()
{
      Next[0]=0;
      int plen=strlen(p);
      for(int i=1,k=0;i<plen;++i)
      {
            while(p[i]!=p[k]&&k) k=Next[k-1];
            if(p[i]==p[k]) ++k;
            Next[i]=k;
      }
}

int kmp()
{
      int ans=0;
      getNext();
      int plen=strlen(p);
      int tlen=strlen(t);
      for(int i=0,k=0;i<tlen;++i)
      {
            while(t[i]!=p[k]&&k) k=Next[k-1];
            if(t[i]==p[k]) ++k;
            if(k==plen)
            {
                  ans++;k=0;
            }
      }
      return ans;
}

int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",t)&&t[0]!='#')
      {
            scanf("%s",p);
            printf("%d\n",kmp());
      }
      return 0;
}
/*

*/
