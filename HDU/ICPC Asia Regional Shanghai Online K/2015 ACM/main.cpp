/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-26-13.19
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
#define ls l, m, rt << 1
#define rs m+1, r, rt << 1|1
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
using namespace std;
typedef long long LL;
const int maxn = 1e5;
LL sum[(maxn << 2) + 131];
LL M;

void create(LL l, LL r, LL rt)
{
      sum[rt] = 1;
      if(l == r) return ;
      LL m = (l + r) >> 1;
      create(ls);
      create(rs);
}

void  pushup(LL rt)
{
      sum[rt] = sum[rt<<1] * sum[rt<<1|1] % M;
}

void change(LL pos, LL val, LL l, LL r, LL rt)
{
      if(l == r && l == pos)
      {
            sum[rt] = val;
            return ;
      }
      LL m = (l + r) >> 1;
      if(pos <= m) change(pos, val,ls);
      else change(pos,val, rs);
      pushup(rt);
}

int t;
LL Q,cnt,n,pos;
map<LL, LL> P,mp;
int main()
{
      scanf("%d",&t);
      for(int Cas = 1; Cas <= t; ++ Cas)
      {
            create(1,maxn,1);
            P.clear(),mp.clear();
            cnt = 1;
            scanf("%lld %lld",&Q, &M);
            printf("Case #%d:\n",Cas);
            LL type;
            for(LL i = 1; i <= Q; ++ i)
            {
                  scanf("%lld %lld",&type, &n);
                  if(type == 1)
                  {
                        P[i] = n;
                        mp[n] = cnt;
                        ++cnt;
                        change(cnt-1, n, 1, maxn, 1);
                  }
                  else
                  {
                        n = P[n];
                        pos = mp[n];
                        change(pos,1, 1, maxn, 1);
                  }
                  printf("%lld\n",sum[1]);
            }
      }
}
