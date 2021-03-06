/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-06-23.12
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

struct buff
{
      int t,g,id;
      buff(){}
      buff(int t,int g,int id):t(t),g(g),id(id){}
      bool operator<(const buff& a)const
      {
            return t<a.t||(t==a.t&&id<a.id);
      }
};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int id,gap,k;
      char s[20];
      multiset<buff> bf;
      while(~scanf("%s",s),s[0]!='#')
      {
            scanf("%d %d",&id,&gap);
            bf.insert(buff(gap,gap,id));
      }
      scanf("%d",&k);
      while(k--)
      {
            buff b=*bf.begin();
            bf.erase(bf.begin());
            printf("%d\n",b.id);
            bf.insert(buff(b.t+b.g,b.g,b.id));
      }
      return 0;
}
/*

*/
