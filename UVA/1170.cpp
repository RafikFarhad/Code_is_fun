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
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/******************************************/
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
#define csii                                     pf("Case %d:\n", ++keis)
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
int SET(int mask, int pos){return mask|(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX (1e10+5)
#define MOD 100000007
#define MY INT_MIN
ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
ll EXP(ll base, ll power)
{
    if(power==1) return base;
    return (base)*EXP(base, power-1);
}
ll all[120000];
int cow = 0;
bool flag[100005];
ll fact[2500];
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0);
    ll ans,  c, d, x, y, a, b;
    fact[0] = 1ll;
    for(i=2; i<100001; i++)
    {
        if(i<2400)
            fact[i-1] = (fact[i-2]*(i-1))%MOD;
        a = i;
        if(flag[i]) continue;
        for(j=2; ; j++)
        {
            a = a*i;
            if(a<0 or a>MX) break;
            all[cow++] = a;
            if(a<100001)
                flag[a] = 1;
        }
    }
    sort(all, all+cow);
//    fact[0] = 1ll;
//    for(i=1; i<2400;i++)
//    {
//        //deb(all[i]);
//        fact[i] = (fact[i-1]*i)%MOD;
//    }
    ll *ita, *itb;
    takei(t);
    while(t--)
    {
        takell(a);
        takell(b);
        if(b<a) swap(a,b);
        ita = lower_bound(all, all + cow, a);
        itb = lower_bound(all, all+cow, b+1);
        c = itb-ita;
        //deb(c);
        if(!c or c<0)
        {
            csi;
            _(0);
            continue;
        }
        ans = fact[2*c];
        a = (fact[c+1]*fact[c])%MOD;
//        deb(a);
        a = FAST_EXP(a, MOD-2ll);
        //while(a<0) a+=MOD;
        ans = (ans*a)%MOD;
        //while(a<0) a+=MOD;
        csi;
        pf("%lld\n", ans);
    }
//

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



