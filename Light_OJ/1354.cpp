/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 46400
int BIN_DEC(int k)
{
    int sum = 0, base=1;
    while(k)
    {
        sum+=(base*(k%10));
        k/=10;
        base*=2;
    }
    return sum;
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, a, b, c, d, e, f, g, h;
    takei(t);
    while(t--)
    {
        sf("%d.%d.%d.%d", &a, &b, &c, &d);
        sf("%d.%d.%d.%d", &e, &f, &g, &h);
        if(a==BIN_DEC(e) && b==BIN_DEC(f) && c==BIN_DEC(g) && d==BIN_DEC(h)) pf("Case %d: Yes\n", ++keis);
        else pf("Case %d: No\n", ++keis);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

