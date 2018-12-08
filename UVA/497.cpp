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
#define SIZE INT_MAX
int ar[1005], dp[1005], path[1005], n;

int CALL(int pos)
{

    int &ret = dp[pos];
    if(~ret) return ret;
    ret = 0;
    int i, j=0;
    for(i=pos+1; i<n; i++)
    {
        if(ar[pos]<ar[i])
        {
            int k = CALL(i);
            if(k>j)
            {
                j = k;
                path[pos] = i;
            }
        }
    }
    ret = 1+j;
    return ret;
}

void PP(int pos, int i=0)
{
    //deb(pos, path[pos]);
    if(path[pos]==-1) return;
    pf("%d\n", ar[path[pos]]);
    PP(path[pos]);
    return;
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
    char pp[10];
    int t;
    sf("%d", &t);
    getchar();
    getchar();
    //deb(t);
    while(t--)
    {
        n = 0;
        while(gets(pp) and strlen(pp))
        {
            //deb(pp, "*");
            if(strlen(pp)==0)
                break;
            ar[n++] = stoi(pp, nullptr, 10);
        }
       /* for(i=0; i<n; i++)
            deb(ar[i]);
            NL; ok*/
        //deb(n);
        CLR1(dp);
        CLR1(path);
        b = 0;
        c = 0;
        for(i=0; i<n; i++)
        {
            d = CALL(i);
            if(d>=b)
            {
                b = d;
                c = i;
            }
        }
        pf("Max hits: %d\n", b);
        //pf("%d\n", b);
       // deb(c);
       pf("%d\n", ar[c]);
         PP(c);
        if(t) NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
