
/*Winter is coming*/


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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-03-27-01.32 _ Monday       */
/****************************************************/
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
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

#define SIZE 100005

class POINT
{
public:
    double x, y;
    int id;
    POINT(double _x=0.0, double _y=0.0, int iid=0): x(_x), y(_y), id(iid) {};

};
bool COMPA2(POINT a, POINT b)
{
     if(b.x==a.x)
        return a.y< b.y;
    return a.x<b.x;
}
vector <POINT> point, aux, tt, pp;
vector <POINT> answer;

int n;

double AREA(POINT a, POINT b, POINT c)
{
    return (a.x*(b.y-c.y) + a.y*(c.x-b.x) + (b.x*c.y-b.y*c.x));
}

void CONVEX_HULL()
{
    int i, j, k, l;
    sort(point.begin(), point.end(), COMPA2);
    POINT p1, p2;
    stack<POINT>low;
    stack<POINT>up;
    sort(all(point), COMPA2);
    for(i=0; i<n; i++)
    {
        while(low.size()>=2)
        {
            p2=low.top();
            low.pop();
            p1=low.top();
            if(AREA(p1, p2, point[i] )>=0)
            {
                low.push(p2);
                break;
            }
        }
        low.push(point[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        while(up.size()>=2)
        {
            p2=up.top();
            up.pop();
            p1=up.top();
            if(AREA(p1, p2, point[i])>=0)
            {
                up.push(p2);
                break;
            }
        }
        up.push(point[i]);
    }
    low.pop();
    up.pop();
    while(!up.empty())
    {
        answer.pb(up.top());
        up.pop();
    }
    while(!low.empty())
    {
        answer.pb(low.top());
        low.pop();
    }
    reverse(all(answer));

    return;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    double pp, qq;
    char cc;
    takei(t);
    while(t--)
    {
        takei(n);
        point.clear();
        a = 0;
        for(i=0; i<n; i++)
        {
            getchar();
            sf("%lf %lf %c", &pp, &qq, &cc);
            if(cc=='Y')
            {
                a++;
                point.pb(POINT(pp, qq, a-1));
                //deb(pp, qq);
            }
        }
        answer.clear();
        n = point.size();
        CONVEX_HULL();
        a = answer.size();
        pf("%d\n", a);
        for(i=0; i<a; i++)
        {
            pf("%d %d\n", (int)answer[i].x, (int)answer[i].y);
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



