/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-13-09.05
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

const int MAXN=150050;
int k,m,q;

int val[MAXN];
vector<string> name;
set<pair<int,int> > pq;

struct Query
{
      int q;
      int idx;
      int ans;
      bool operator<(const Query& a) const
      {
            return q<a.q;
      }

}tquery;
vector<Query> query;

int t[MAXN],p[MAXN];
int q[110];
char tname[250],v;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d %d %d",&k,&m,&q);
            name.clear();
            for(int i=0;i<k;++i)
            {
                  scanf("%s %d",tname,&v);
                  val[i]=v;
                  name.push_back(string(tname));
            }
            for(int i=0;i<m;++i)
            {
                  scanf("%d %d",&t[i],&p[i]);
            }
            query.clear();
            for(int i=1;i<=q;++i)
            {
                  scanf("%d",&q[i]);
                  tquery.q=q[i];
                  tquery.idx=i;
                  query.push_back(tquery);
            }
            sort(query.begin(),query.end());
            pq.clear();
            int j=0;
            for(int i=0;i<k;++i)
            {
                  pq.insert(make_pair(val[i],i));
                  if(i==query[j].q)
                  {
                        query[j].ans=pq.front().second;
                        pq.clear();
                  }
            }
            for(int i=0;i<q;++i)
            {
                  for(int j=0;j<q;++j)
                  {
                        if(i==query[j].q)
                        {
                              printf("%s",name[query[j].ans]);
                        }
                  }
            }

      }
      return 0;
}
/*

*/
