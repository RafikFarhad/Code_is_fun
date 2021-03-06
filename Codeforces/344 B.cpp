#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
int r[5005][3], c1[5005][3];
int main()
{
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int  n, m;
    takei(n);
    takei(m);
    takei(k);
    for(i=0; i<n; i++)
        r[i][0]= r[i][1] = 0;
    for(i=0; i<m; i++)
        c1[i][0]= c1[i][1] = 0;

    for(i=1;i<=k; i++)
    {
        takei(a);
        takei(b);
        takei(c);
        if(a==1)
        {
            b--;
            r[b][0] = c;
            r[b][1] = i;
        }
        else
        {
            b--;
            c1[b][0] = c;
            c1[b][1] = i;
        }

    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            j?pf(" "):1;
            if(r[i][1]>c1[j][1]) pf("%d", r[i][0]);
            else pf("%d", c1[j][0]);
        }
        NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

