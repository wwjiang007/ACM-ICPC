/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-26-16.56
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
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)

#define pi acos(-1.0)
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

using namespace std;
int T;
struct P
{
      double x,y;
      P() {}
      P(double x,double y):x(x),y(y) {}
      P operator + (P p)
      {
            return P(x+p.x,y+p.y);
      }
      P operator - (P p)
      {
            return P(x-p.x,y-p.y);
      }
      P operator / (double d)
      {
            return P(x/d,y/d);
      }
      double dot(P p)
      {
            return x*p.x+y*p.y;
      }
};
double difjsd(double  x1,double y1,double x2,double y2)
{
      double dx=x1-x2,dy=y1-y2;
      return sqrt(dx*dx+dy*dy);
}
double difjsd(P a,P b)
{
      double dx=a.x-b.x,dy=a.y-b.y;
      return sqrt(dx*dx+dy*dy);
}
double x1,x2,x3,y1,y2,y3;
int main()
{
      cin>>T;
      int Cas=0;
      while(T--)
      {
            scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
            double c=difjsd(x1,y1,x2,y2);
            double b=difjsd(x1,y1,x3,y3);
            double a=difjsd(x2,y2,x3,y3);
            double p=(a+b+c)/2;
            double mx=(x2+x3)/2,my=(y2+y3)/2;
            double answer=difjsd(mx,my,x1,y1);
            double s=sqrt(p*(p-a)*(p-b)*(p-c));
            P B(x2,y2);
            P A(x1,y1);
            P M(mx,my);
            double  bm=difjsd(B,M);
            double  jdm=difjsd(A,M);
            double t=bm*bm/jdm;
            double reso=sqrt(bm*bm+t*t);
            double jd=acos(bm/b);
            answer+=reso*jd*2;
            printf("Case #%d: %.4lf\n",++Cas,answer);
      }
      return 0;
}
