///Only Sakibul Mowla vai is real :P



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
#define csi                                     pf("Case %d:", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

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
#define SIZE 100005

int lca[SIZE][20], ans[SIZE][20], n, m, ar[SIZE];

void BUILD_LCA()
{
    int i, j, lg = 18;
    for(i=0; i<n; i++)
    {
        for(j=1; j<=lg; j++)
        {
            lca[i][j] = -1;
            ans[i][j] = 1<<29;
        }
    }
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<n; i++)
        {
            if(lca[i][j-1]!=-1)
            {
                lca[i][j] = lca[lca[i][j-1]][j-1];
                ans[i][j] = min(ans[lca[i][j-1]][j-1], ans[i][j-1]);
            }
            //if(i==5 and j==1) deb("*",lca[lca[i][j-1]][j-1], lca[i][j-1], lca[i][j]);
        }
    }
    return;
}

int QUEIRY(int a, int b)
{
    //if(ar[a]>=b) return a;
    //deb(a, b);
    for(int i=17; i>=0; i--)
    {
        //deb(i, lca[a][i], ans[a][i]);
        if(lca[a][i]!=-1 and ans[a][i]>b)
        {
            //ok
            //deb(i, ans[a][i], lca[a][i]);
            a = lca[a][i];
        }
    }
    //deb(a, ans[a][0], ar[lca[a][0]]);
    if(ar[lca[a][0]]==b) return lca[a][0];
    return a;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int t;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        for(i=1; i<n; i++)
        {
            takei(a);
            takei(b);
            lca[i][0] = a;
            ar[i] = b;
        }
        ar[0] = 1;
        lca[0][0] = -1;
        for(i=1; i<n; i++)
        {
            ans[i][0] = ar[lca[i][0]];
        }
        ans[0][0] = 1;
        BUILD_LCA();
        //deb(ans[5][0], ans[5][1]);
        csi;
        NL;
        while(m--)
        {
            takei(a);
            takei(b);
            pf("%d\n", QUEIRY(a, b));

        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

