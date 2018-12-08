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
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
#define SIZE 2000005
long long tree[SIZE<<2], start, last, n, val, ar[SIZE], lucky[SIZE];
vector <ll> my;
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = lucky[i] = i&1?1:0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = tree[left]  + tree[right];
    return;
}
void UPDATE(int i, int j, int node, int val)
{
    if(i==j)
    {
        tree[node] = 0;
        lucky[i] = 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    if(tree[left]>=val) UPDATE(i, mid, left, val);
    else UPDATE(mid+1, j, right, val-tree[left]);
    tree[node] = tree[left]  + tree[right];
    return;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0);
    ll c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    i;
    my.pb(0);
    my.pb(1);
    CLR(lucky);
    INIT(1, SIZE, 1);

    for(i=3; i<SIZE; i+=2)
    {
        if(lucky[i]==1)
        {
            my.pb(i);
            //deb(i);
            a = (SIZE/i)*i;
            for(j=a; j>=i; j-=i)
            {
                UPDATE(1, SIZE, 1, j);
            }
        }
    }

    while(sf("%lld", &a)!=EOF)
    {
        if(a&1)
        {
            pf("%lld is not the sum of two luckies!\n", a);
            continue;
        }
        b = a>>1;
        c = lower_bound(my.begin(), my.end(), b) - my.begin();
        if(lucky[b]==0)
            c--;
        //deb(c);
        for(i=c; i>0; i--)
        {
            if(lucky[a-my[i]]==1)
            {
                pf("%lld is the sum of %lld and %lld.\n", a, my[i], a-my[i]);
                i = -2;
            }
        }
        if(i==-1)
        {
            pf("%lld is not the sum of two luckies!\n", a);
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


