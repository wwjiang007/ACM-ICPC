/*
* this code is made by crazyacking
* Submission Date: 2015-07-30-14.53
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

int n,a[44722];
void pre()
{
      for(int i=0;1;++i)
      {
            a[i]=(1+i)*i/2;
            if(a[i]>1000000050) return ;

      }

}

void out(int a)
{
    if(a>9)
        out(a/10);
    putchar(a%10+'0');
}

int main()
{
      pre();
      while(~scanf("%d",&n))
      {
            int idx=0;
            for(int i=0;i<44722;++i)
            {
                  if(n>a[i]&& n<=a[i+1])
                  {
                      idx=i+1;break;
                  }
            }
            int same=0;
            bool haveAns=false;
            LL abandon=0;
            for(same=0;same<=idx;++same)
            {
                  abandon=(LL)(1+same)*same/2;
                  if(a[idx]-abandon==n)
                  {
                        haveAns=true;
                        break;
                  }
            }
            if(haveAns)
            {
                  printf("%d\n",idx);
                  int i;
                  if(same==0)
                        for(int i=1;i<=idx;++i)
                              printf(i==idx?"%d\n":"%d ",i);
                  else
                  {
                        int i;
                        for(i=1;i<=idx-same;++i)
                        {
                              out(i);
                              printf(" ");
                        }
                        i--;
                        for(int j=1;j<=same;++j)
                        {
                              if(j==same)
                              {
                                    out(i);
                                    puts("");
                              }
                              else
                              {
                                    out(i);
                                    printf(" ");
                              }
                        }
                  }
            }
            else
                  for(int i=1;i<=n;++i)
                        if(i==n) printf("1\n");
                        else printf("1 ");
      }
      return 0;
}
/*

*/