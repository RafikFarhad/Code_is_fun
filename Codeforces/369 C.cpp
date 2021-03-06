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
#define csi                                     pf("Case %d: ", ++keis)
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
#define MX (1l<<50)
#define MOD 105
#define MY INT_MIN
ll dp[MOD][MOD][MOD];
bool flag[MOD][MOD][MOD];
int n, m, k, c[MOD], p[MOD][MOD];

ll GO(int x, int y, int z)
{
    //deb(x, y, z);
    if(z==k+1)
    {
        return MX;
    }
    if(x==n+1)
    {
       // deb("==========", x, z);
        if(z==k) return 0;
        return MX;
    }
    ll &ret = dp[x][y][z];
    if(flag[x][y][z]) return  ret;
    flag[x][y][z] = 1;
    if(c[x]!=0)
    {
        if(y==c[x])
        {
            return ret = GO(x+1, y, z);
        }
        else
        {
            return ret = GO(x+1, c[x], z+1);
        }
    }
    ll cost = MX, a;
    for(int i=1; i<=m; i++)
    {
        if(y==i)
        {
            a = GO(x+1, y, z) + p[x][i];
        }
        else
        {
            a = GO(x+1, i, z+1) + p[x][i];
        }
        cost = min(cost, a);
        //deb("a", a, p[x][i]);
    }
    return ret = cost;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, l,  keis=0, a, b, d, x, y;
    deb(MX);
    takei(n);
    takei(m);
    takei(k);
    for(i=0; i<n; i++)
        takei(c[i+1]);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            takei(p[i+1][j+1]);
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            for(t=0; t<=k; t++)
            {
                dp[i][j][t] = MX;
                flag[i][j][t] = 0;
            }
        }
    }
    if(c[1])
    {
        ll ans = GO(1, c[1], 1);
        if(ans>=MX)
            cout << -1  << endl;
        else
            cout << ans  << endl;
    }
    else
    {
        ll ans = GO(1, c[1], 0);
        if(ans>=MX)
            cout << -1  << endl;
        else
            cout << ans  << endl;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



