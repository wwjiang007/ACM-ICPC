/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-27-15.16
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
#define MAX(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


const int MAXN = 100110;
const int Mod = (int) 1e9 + 7;

int S[MAXN],a[MAXN], n, L,f[MAXN], t[MAXN], pd[MAXN];
int get_val(int x);
void update(int x, int k);
LL tt;
vector<int> b;
vector<int> Last;
void init()
{
      b.clear();
      memset(S, 0, sizeof S);
}
int main()
{
      scanf("%I64d", &tt);
      for(LL Cas=1;Cas<=tt;++Cas)
      {
            scanf("%d %d", &n , &L);
            init();
            for(int i = 1; i <= n; ++i)
            {
                  scanf("%d", &a[i]);
                  b.push_back(a[i]);
            }
            sort(b.begin(), b.end());
            sort(b.begin(), b.end());
            b.erase(unique(b.begin(), b.end()), b.end());
            for(int i = 1; i <= n; ++i)
            {
                  a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
                  a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
            }
            Last.clear();
            vector<int> ::iterator it;
            for(int i = 1; i <= n; ++i)
            {
                  it = lower_bound((Last).begin(),(Last).end(), a[i]);
                  t[i] = it - Last.begin() + 1;
                  if(it == Last.end())
                  {
                        Last.push_back(a[i]);
                  }
                  else
                  {
                        *it = min(*it, a[i]);
                  }
            }
            Last.clear();
            for(int i = n; i > 0; --i)
            {
                  it = lower_bound((Last).begin(),(Last).end(), -a[i]);
                  f[i] = it - Last.begin() + 1;
                  if(it == Last.end()) Last.push_back(-a[i]);
                  else *it = min(*it, -a[i]);
            }
            Last.clear();
            int ans = 0;
            for(int i = 1; i <= (n - L); ++i)
            {
                  ans = MAX(ans, t[i]);
            }
            Last.clear();
            for(int i = L + 1; i <= n; ++i)
            {
                  ans = MAX(ans, f[i]);
            }
            Last.clear();
            for(int i = 2; i + L <= n; ++i)
            {
                  update(a[i-1],t[i-1]);
                  int p = i + L;
                  p = i + L;
                  ans = MAX(ans, get_val(a[p]) + f[p]);
            }
            printf("Case #%I64d: %d\n", Cas, ans);
      }
}


void update(int x, int k)
{
      for(x; x <= MAXN; x += x & -x)
            S[x] = MAX(S[x], k);
}

int get_val(int x)
{
      int ans = 0;
      for(x; x > 0; x -= x & -x)
            ans = MAX(ans, S[x]);
      return ans;
}
