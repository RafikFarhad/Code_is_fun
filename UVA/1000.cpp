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
#define csll                                    pf("Case %lld: ", ++keis)
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
#define SIZE INT_MAX
class DATA
{
public:
    int togate[30], pass[30];
    DATA()
    {
        CLR(togate);
        CLR(pass);
    }

};

DATA ar[30];
int n, posa[30], posb[30];

int COUNT(int x)
{
    int a, i, j, k, tot;
    //deb("#", x);
    a = posa[x];
    tot = 0;
    for(i=1; i<=n; i++)
    {
        if(ar[a].togate[i])
        {
            for(j=1; j<=n; j++)
            {
                if(posb[j]==i)
                    break;
            }
            //deb("->", a, i, j);
            k = abs(j-x);
            tot = tot + ar[a].togate[i]*(k+1);
        }
    }
    return tot;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, con, tot;
    vector < pair<int, int> > v;
    while(sf("%d", &n) and n)
    {
        v.clear();
        for(i=1; i<=n; i++)
        {
            takei(j);
            ar[j] = DATA();
            takei(k);
            //deb("*", k);
            while(k--)
            {
                takei(a);
                takei(b);
                ar[j].togate[a] = b;
            }
        }
        pf("Configuration Load\n");
        while(sf("%d", &con)==1 and con)
        {
            //deb("-> ", con);
            CLR(posa);
            CLR(posb);
            tot = 0;
            for(i=1; i<=n; i++)
            {
                takei(posa[i]);
            }
            for(i=1; i<=n; i++)
            {
                takei(posb[i]);
            }
            for(i=1; i<=n; i++)
            {
                tot+=COUNT(i);
                //deb(i, COUNT(i));
            }
            //pf("total: %d\n", tot);
            v.pb({tot, con});
        }
        sort(all(v));
        for(i=0; i<v.size(); i++)
        {
            pf("%5d         %d\n", v[i].second, v[i].first);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



