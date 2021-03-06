//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

//defines-general
typedef long long ll;
typedef long double ld;
#define to(a) __typeof(a)
#define fill(a,val)  memset(a,val,sizeof(a))
#define repi(i,a,b) for(__typeof(b) i = a;i<b;i++)

//defines-pair
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define ff first
#define ss second
#define mp make_pair

//defines-vector
typedef vector<int> vi;
typedef vector<long long> vll;
#define all(vec)  vec.begin(),vec.end()
#define tr(vec,it)  for(__typeof(vec.begin())  it = vec.begin();it!=vec.end();++it)
#define pb push_back
#define sz size()
#define contains(vec,x) (find(vec.begin(),vec.end(),x)!=vec.end())

int main()
{
      vector<pii > vals;
      char ans[2000][2000];
      repi(i, 0, 2000)
      {
            repi(j, 0, 2000) ans[i][j] = ' ';
      }
      int n;
      cin >> n;
      int x=0,y=0;
      vals.pb(mp(x,y));
      int maxy=0;
      int maxx=1;
      int add = 1;
      repi(i, 0, n)
      {
            int a;
            cin >> a;
            x+=a;
            y+=((i%2==0)?1:-1)*a;
            maxy = max(y,maxy);
            maxx = max(x,maxx);
            vals.pb(mp(x,y));
      }
      repi(i, 0, n+1)
      {
            vals[i].ss = -1*(vals[i].ss-maxy);
      }
      repi(i, 1, n+1)
      {
            x = vals[i-1].ff;
            y = vals[i-1].ss;
            int x1 = vals[i].ff;
            int y1 = vals[i].ss;
            if(i%2)
            {
                  for(int j = y1+1; j<=y; j++)
                  {
                        ans[j-1][x1-(j-y1)] = '/';
                  }
            }
            else
            {
                  for(int j = y+1; j<=y1; j++)
                  {
                        ans[j-1][x+(j-y-1)] = '\\';
                  }
            }
      }
      int maxi = 0;
      int maxj = 0;
      repi(i, 0, 1010)
      {
            repi(j, 0, 1010)
            {
                  if(ans[i][j]!=' ')
                  {
                        maxi = max(i,maxi);
                        maxj = max(j,maxj);
                  }
            }
      }
      repi(i, 0, maxi+1)
      {
            repi(j, 0, maxj+1) printf("%c",ans[i][j]);
            cout << endl;
      }
//    for(pii temp:vals) cout << temp.ff <<" " << temp.ss << endl; cout << endl;
      return 0;
}
