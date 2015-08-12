/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-11-22.57
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

const int MAXN=110010;
int n;
struct Node
{
      int rad,idx;
      bool operator <(Node a) const
      {
            return rad>a.rad;
      }
};
Node Mp[MAXN*2];

/** O(n)内求出所有回文串
 *原串 :abaaba
 *Ma串 :.,a,b,a,a,b,a,
 *Mp[i]:Ma串中，以字符Ma[i]为中心的最长回文子串的半径长度(包括Ma[i],也就是把回文串对折后的长度).
 ****经过对原串扩展处理后，将奇数串的情况也合并到了偶数的情况(不需要考虑奇数串)
 */
int Ma[MAXN*2],s[MAXN];
int Mplen;
void Manacher(int s[],int len)
{
      int le=0;
      Mp[le].rad=0,Mp[le].idx=0;
      Ma[le++]='.';
      Mp[le].rad=1,Mp[le].idx=-1;
      Ma[le++]=',';
      for(int i=0;i<len;++i)
      {
            Mp[le].idx=le;
            Ma[le++]=s[i];
            Mp[le].idx=-le;
            Ma[le++]=',';
      }
      Mplen=le;
      Ma[le]=0;
      int pnow=0,pid=0;
      for(int i=1;i<le;++i)
      {
            if(pnow>i)
                  Mp[i].rad=min(Mp[2*pid-i].rad,pnow-i);
            else
                  Mp[i].rad=1;
            for(;Ma[i-Mp[i].rad]==Ma[i+Mp[i].rad];++Mp[i].rad);
            if(i+Mp[i].rad>pnow)
            {
                  pnow=i+Mp[i].rad;
                  pid=i;
            }
      }
}



bool judge(int x)
{
      // 偶数
      if(Mp[x].idx<=0)
      {
//            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");
//            cout<<Mp[x].idx<<endl;
//            cout<<Mp[x].rad<<endl;
//            cout<<Mp[x].idx<<endl;
            int idx=abs(Mp[x].idx)/2-1;
            int rad=Mp[x].rad/2;
            int Xst=idx-rad+1;
            int Xen=idx;
            int Yst=idx+rad+1;
            int Yen=idx+rad*2;

//            cout<<Xst<<" "<<Xen<<endl;
//            cout<<Yst<<" "<<Yen<<endl;
//            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");
            if((Xen-Xst+1)!=rad  ||  (Yen-Yst+1)!=rad ) return false;
            if(Xen>=n || Yen>=n) return false;
            bool flag=true;
            for(int i=Xst,j=Yst;i<=Xen;++i,++j)
            {
                  if(!(s[i]!=s[j]))
                  {
                        flag=false;
                        break;
                  }
            }
            if(flag) return false;
            return true;
      }
      // 奇数
      else
            return false;

}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1;Cas<=t;++Cas)
      {
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&s[i]);
            }
            Manacher(s,n);
            int idx=0;
//            for(int i=0;i<Mplen;++i)
//            {
//                  printf("%d ",Mp[i].rad);
//            }
//            cout<<endl;
//            for(int i=0;i<Mplen;++i)
//            {
//                  printf("%d ",Mp[i].idx);
//            }
//            cout<<endl;



            sort(Mp,Mp+Mplen);
//            for(int i=0;i<Mplen;++i)
//            {
//                  printf("%d ",Mp[i].rad);
//            }
//            cout<<endl;
//            for(int i=0;i<Mplen;++i)
//            {
//                  printf("%d ",Mp[i].idx);
//            }
//            cout<<endl;

            //
            int ans=0;
            for(int i=0;i<Mplen;++i)
            {
                  if(judge(i))
                  {
                        ans=(Mp[i].rad-1)/2*3;
                        break;
                  }
            }
            printf("Case #%d: %d\n",Cas,ans);
      }
      return 0;
}
