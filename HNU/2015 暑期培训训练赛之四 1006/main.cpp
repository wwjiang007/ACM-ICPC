/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-02-17.06
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
#include <ctime>
#include <bits/stdc++.h>
#define  LL long long
#define  ULL unsigned long long
using namespace std;
const LL MAXN = 100010;

LL n, p;
LL x[MAXN], y[MAXN];
int main()
{
      srand( time( NULL ) );
      while( ~scanf( "%lld %lld", &n, &p ) )
      {
            for( LL i = 0; i < n; ++i )
                  scanf( "%lld %lld", &x[i], &y[i] );
            if( n == 1 ) { puts( "possible" ); continue; }
            LL sum=0;
            if( n * p % 100 == 0 ) sum = n * p / 100;
            else sum = n * p / 100 + 1;
            LL T = 20,num;
            bool flag = false;
            bool ff[10];
            memset(ff,0,sizeof ff);
            while( T-- )
            {
                  LL a = ( LL )rand() * ( LL )rand() % n;
                  LL b = ( LL )rand() * ( LL )rand() % n;
                  cout<<a<<" "<<b<<endl;
                  ff[a]=1,ff[b]=1;
                  if( a == b ) continue;
                  num = 2;
                  for( LL j = 0; j < n; ++j )
                  {
                        if( j == a || j == b ) continue;
                        if( ( y[j] - y[a] ) * ( x[b] - x[a] ) == ( x[j] - x[a] ) * ( y[b] - y[a] ) ) num++;
                  }
                  if( num >= sum ) {flag = true; break;}
            }
            for(int i=0;i<n;++i)
            {
                  if(!ff[i]) printf("hehe %d\n",i);
            }
            if( flag ) puts( "possible" );
            else puts( "impossible" );
      }
      return 0;
}
/*

*/
