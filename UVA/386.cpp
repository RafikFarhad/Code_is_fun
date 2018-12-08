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
ll ar[205];
int flag[8000005];

class DATA
{
public:
    int a, b, c, d;
    DATA(int aa, int ab, int ac, int ad) : a(aa), b(ab), c(ac), d(ad){};
    bool operator < (const DATA &p) const
    {
        if(a==p.a)
        {
            if(b==p.b)
            {
                if(c==p.c)
                {
                    return c<p.c;
                }
                return c<p.c;
            }
            return b<p.b;
        }
        return a<p.a;
    }
};
vector <DATA> ans;

void GO(int pos=2, int taken=0, ll sum=0ll, int a=0, int b=0, int c=0)
{
   /* if(a==3 and b==4 and c==5)
    {
        deb(sum);
        if(flag[sum]) ok;
    }*/
    if(sum>8000000) return;
    if(taken==3)
    {
        if(sum>8000000) return;
        if(flag[sum])
        {
            ans.pb(DATA(flag[sum], a, b, c));
        }
        return;
    }
    if(pos==201) return;
    GO(pos+1, taken, sum, a, b, c);
    if(taken==0)
    {
        GO(pos+1, taken+1, sum+ar[pos], pos, 0, 0);
    }
    else if(taken==1)
    {
        GO(pos+1, taken+1, sum+ar[pos], a, pos, 0);
    }
    else if(taken==2)
    {
        GO(pos+1, taken+1, sum+ar[pos], a, b, pos);
    }
    return;

}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    for(i=1; i<201; i++)
    {
        ar[i] = (ll)(i*i*i);
        flag[ar[i]] = i;
    }
    GO();
    l  = ans.size();
    sort(all(ans));
    for(i=0; i<l; i++)
    {
        pf("Cube = %d, Triple = (%d,%d,%d)\n", ans[i].a, ans[i].b, ans[i].c, ans[i].d);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

