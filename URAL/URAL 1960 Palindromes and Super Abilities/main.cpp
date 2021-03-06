/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-19-13.56
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

const int MAXN = 200050 ;
const int N = 26 ;
char s[MAXN];
struct Palindromic_Tree
{
      int next[MAXN][N] ;//next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
      int fail[MAXN] ;//fail指针，失配后跳转到fail指针指向的节点
      int cnt[MAXN] ;//节点i回文串在总串中出现的次数
      int num[MAXN] ; //当前节点通过fail指针到达0节点或1节点的步数(fail指针的深度)
      int len[MAXN] ;//节点i回文串的长度
      int S[MAXN] ;//存放添加的字符
      int last ;//指向上一个字符所在的节点，方便下一次add
      int n ;//字符数组指针
      int p ;//节点指针
      int newnode(int l)     //新建节点
      {
            for(int i = 0 ; i < N ; ++ i) next[p][i] = 0 ;
            cnt[p] = 0 ;
            num[p] = 0 ;
            len[p] = l ;
            return p ++ ;
      }
      void init()   //初始化
      {
            p = 0 ;
            newnode(0) ;
            newnode(-1) ;
            last = 0 ;
            n = 0 ;
            S[n] = -1 ;//开头放一个字符集中没有的字符，减少特判
            fail[0] = 1 ;
      }
      int get_fail(int x)     //和KMP一样，失配后找一个尽量最长的
      {
            while(S[n - len[x] - 1] != S[n]) x = fail[x] ;
            return x ;
      }
      void add(int c)
      {
            printf("%d:",p);
            c -= 'a' ;
            S[++ n] = c ;
            int cur = get_fail(last) ;   //通过上一个回文串找这个回文串的匹配位置
            if(!next[cur][c])     //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            {
                  int now = newnode(len[cur] + 2) ;   //新建节点
                  fail[now] = next[get_fail(fail[cur])][c] ;   //和AC自动机一样建立fail指针，以便失配后跳转
                  next[cur][c] = now ;
                  num[now] = num[fail[now]] + 1 ;
            } last = next[cur][c] ;
            cnt[last] ++ ;
      }
      void count()
      {
            for(int i = p - 1 ; i >= 0 ; -- i) cnt[fail[i]] += cnt[i] ;
            //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
      }
} tree1,tree2;

LL ans=0;
void dfs(int sta)
{
      int now=sta;

}

int main()
{
      int t;
      scanf("%d",&t);
      for(int Cas=1;Cas<=t;++Cas)
      {
            tree1.init(),tree2.init();
            scanf("%s",s);
            for(int i=0;s[i];++i)
                  tree1.add(s[i]);
            scanf("%s",s);
            for(int i=0;s[i];++i)
                  tree2.add(s[i]);
            tree1.count(),tree2.count();
            ans=0;
            dfs(0),dfs(1);
            cout<<ans<<endl;
      }
      return 0;
}
