/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-26-16.28
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

#define M_PI 3.14159265358979323846
#define j2h(x) (M_PI*(x)/180.0)

struct point
{
      double x,y;
};


double get_dis(point a,point b)
{
      double xx=fabs(a.x-b.x);
      double yy=fabs(a.y-b.y);
      return sqrt(xx*xx+yy*yy);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      point A,B,C;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%ld %ld %ld %ld %ld %ld",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
            point M;
            M.x=(B.x+C.x)/2.;
            M.y=(B.y+C.y)/2.;
            double len1=get_dis(A,M);
            double len2=get_dis(A,B);
            double len3=get_dis(B,M);
            double len4=len2*len3/len1;
            double r=len4;
            
            asin(sin())*180.0/M_PI
            
      }
      return 0;
}
/*

*/