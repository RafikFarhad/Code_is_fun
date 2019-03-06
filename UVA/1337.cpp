#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
int ar[500][500], n, m, q, flag[500][500], level[500][500];
char in[500][500];

int DFS_1(int a, int b)
{
    flag[a][b] = 1;
    int aa = 0, x, y;
    if(in[a][b]=='C') aa++;
  //  deb(a, b);
    for(int i=0; i<4; i++)
    {
        x = a+xx[i];
        y = b+yy[i];
//        deb(x, y, );
        if(x < 0 or y<0 or x==n or y==m or in[x][y]=='#' or flag[x][y]!=0) continue;
        aa+=DFS_1(x, y);
    }
    return aa;
}

void DFS(int a, int b, int c)
{
    flag[a][b] = 2;
    level[a][b] = c;
    int aa = 0, x, y;
  //  deb(a, b);
    for(int i=0; i<4; i++)
    {
        x = a+xx[i];
        y = b+yy[i];
//        deb(x, y, );
        if(x < 0 or y<0 or x==n or y==m or in[x][y]=='#' or flag[x][y]==2) continue;
        DFS(x, y, c);
    }
    return;
}


int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        takei(q);
        getchar();
        for(i=0; i<n; i++)
        {
            gets(in[i]);
            //puts(in[i]);
        }
        CLR(flag);
        CLR(level);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(flag[i][j]==0 and(in[i][j]=='.' or in[i][j]=='C'))
                {
                    a = DFS_1(i, j);
                //    deb(a);
                    DFS(i, j, a);
                }
            }
        }
        csi;
        while(q--)
        {
            takei(a);
            takei(b);
            a--;
            b--;
            _(level[a][b]);
        }

    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



