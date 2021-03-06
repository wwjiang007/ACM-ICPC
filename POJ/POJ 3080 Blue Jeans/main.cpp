/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-01-10.25
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

int main()
{
      int t;
      scanf( "%d", &t );
      while( t-- )
      {
            int m;
            char p[11][61];
            scanf( "%d", &m );
            for( int i = 0; i < m; i++ ) scanf( "%s", p[i] );
            char ans[61];
            int len=0,plen=strlen(p[0]);
            for( int i = 0; i <plen; i++ )
            {
                  for( int j = i + 2; j < plen; j++ )
                  {
                        char s[61];
                        strncpy( s, p[0] + i, j - i + 1 );
                        s[j - i + 1] = '\0';
                        bool ok = true;
                        for( int k = 1; ok && k < m; k++ )
                        {
                              if( strstr( p[k], s ) == NULL )
                              {
                                    ok = false;
                              }
                        }
                        if( ok && ( j - i + 1 > len || ( j - i + 1 == len && strcmp( ans, s ) > 0 ) ) )
                        {
                              len = j - i + 1;
                              strcpy( ans, s );
                        }
                  }
            }
            if( len < 3 ) printf( "no significant commonalities\n" );
            else printf( "%s\n", ans );
      }
      return 0;
}
