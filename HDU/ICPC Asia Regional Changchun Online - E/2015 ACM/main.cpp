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


int fa[20010];
int seek(int v)
{
      return v == fa[v] ? v : fa[v]=seek(fa[v]);
}
struct Q
{
      int id, val;
      bool operator <(Q a)const
      {
            return val < a.val;
      }
} yxz[5010];
struct E
{
      int a, b, val;
      bool operator <(E one)const
      {
            return val < one.val;
      }
} ebx[100010];
int num[20010];
int asbx[5010];
int work(int x)
{
      return x * (x - 1);
}
int main()
{
      int T;
      scanf("%d", &T);
      while(T--)
      {
            int n, m, q;
            scanf("%d%d%d", &n, &m, &q);
            for(int i = 0; i < m; i++)
                  scanf("%d%d%d", &ebx[i].a, &ebx[i].b, &ebx[i].val);
            for(int i = 0; i < q; i++)
            {
                  scanf("%d", &yxz[i].val);
                  yxz[i].id = i;
            }
            for(int i = 1; i <= n; i++)
            {
                  fa[i] = i;
                  num[i] = 1;
            }
            sort(ebx, ebx + m);
            sort(yxz, yxz + q);
            int hehe = 0, ans = 0;
            for(int i = 0; i < q; i++)
            {
                  while(hehe < m && ebx[hehe].val <= yxz[i].val)
                  {
                        int t1 = seek(ebx[hehe].a), t2 = seek(ebx[hehe].b);
                        if(t1 != t2)
                        {
                              ans -= work(num[t1]) + work(num[t2]);
                              fa[t2] = t1;
                              num[t1] += num[t2];
                              ans += work(num[t1]);
                        }
                        hehe++;
                  }
                  asbx[yxz[i].id] = ans;
            }
            for(int i = 0; i < q; i++)
                  printf("%d\n", asbx[i]);
      }
      return 0;
}