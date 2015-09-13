
int n, m, p;
const int MAXN = 62010;
int FB[62010];
int Appf[202], Aw[202], As[202];
int FA[62010];
int Bw[202], Bp[202], Bs[202];
inline void pac_one(int f[], int V, int v, int n, int w)
{
      if(n == 0 || v == 0) return;
      if(n == 1)
      {
            for(int i = V; i >= v; --i)
                  if(f[i] < f[i - v] + w) f[i] = f[i - v] + w;
            return;
      }
      if(n * v >= V - v + 1)
      {
            for(int i = v; i <= V; ++i)
                  if(f[i] < f[i - v] + w) f[i] = f[i - v] + w;
            return;
      }
      int va[MAXN], vb[MAXN];
      for(int j = 0; j < v; ++j)
      {
            int *pb = va, *pe = va - 1;
            int *qb = vb, *qe = vb - 1;
            for(int k = j, i = 0; k <= V; k += v, ++i)
            {
                  if(pe  == pb + n)
                  {
                        if(*pb == *qb) ++qb;
                        ++pb;
                  }
                  int tt = f[k] - i * w;
                  *++pe = tt;
                  while(qe >= qb && *qe < tt) --qe;
                  *++qe = tt;
                  f[k] = *qb + i * w;
            }
      }
}
inline void pac_two(int f[], int V, int v, int n, int w)
{
      if(n == 0 || v == 0) return;
      if(n == 1)
      {
            for(int i = V; i >= v; --i)
                  if(f[i] > f[i - v] + w) f[i] = f[i - v] + w;
            return;
      }
      if(n * v >= V - v + 1)
      {
            for(int i = v; i <= V; ++i)
                  if(f[i] > f[i - v] + w) f[i] = f[i - v] + w;
            return;
      }
      int va[MAXN], vb[MAXN];
      for(int j = 0; j < v; ++j)
      {
            int *pb = va, *pe = va - 1;
            int *qb = vb, *qe = vb - 1;
            for(int k = j, i = 0; k <= V; k += v, ++i)
            {
                  if(pe  == pb + n)
                  {
                        if(*pb == *qb) ++qb;
                        ++pb;
                  }
                  int tt = f[k] - i * w;
                  *++pe = tt;
                  while(qe >= qb && *qe > tt) --qe;
                  *++qe = tt;              //元素X也存放入辅助队列
                  f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值
            }
      }
}
int main()
{
      int T;
      scanf("%d", &T);
      while(T--)
      {
            memset(FB, 0, sizeof FB);
            memset(FA, 0x3f, sizeof FA);
            scanf("%d %d %d", &n, &m, &p);
            int sva = 0, svb = 0;
            FA[0] = 0;
            for(int i = 1; i <= n; ++i)
            {
                  scanf("%d %d %d", &Aw[i], &Appf[i], &As[i]);
                  pac_two(FA, 51000, Aw[i], As[i], Appf[i]);
            }
            for(int i = 51000; i >= p; --i)
            {
                  FA[i] = min(FA[i], FA[i + 1]);
            }
            for(int i = 1; i <= m; ++i)
            {
                  scanf("%d %d %d", &Bp[i], &Bw[i], &Bs[i]);
                  svb += Bw[i] * Bs[i];
                  pac_one(FB, 51000, Bw[i], Bs[i], Bp[i]);
            }
            int p1 = FA[p], p2;
            int f = 0;
            for(p2 = 1; p2 <= svb; ++p2)
            {
                  if(FB[p2] >= p1)
                  {
                        f = 1;
                        break;
                  }
            }
            if(f) printf("%d\n", p2);
            else puts("TAT");
      }
}
