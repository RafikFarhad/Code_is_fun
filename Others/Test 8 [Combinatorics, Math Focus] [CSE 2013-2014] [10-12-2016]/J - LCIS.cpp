/**         HODOR          **/



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
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
//#define mp                                      make_pair
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
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
int ans[505], path[505], ar[505], br[505], n, m;
//vector <int> tt1, tt2;
//map <pair<int, pair<int, int> >, bool > mp;
//
//int GO(int a, int b, int prev)
//{
//    if(a==n or b==m)
//    {
//        //NL;
//        //deb(tt1.size());
//        if(tt1.size()>tt2.size())
//            tt2 = tt1;
//        return 0;
//    }
//    int &ret = ans[a][b], i;
//    if(mp[{a,{b,prev}}]) return mp[{a,{b,prev}}];
//
//    //if(~ret) return ret;
//    ret = GO(a+1, b+1, prev);;
//    for(i=a; i<n; i++)
//    {
//        if(ar[i]==br[b] and ar[i]>prev)
//        {
//            //pf("%d ", ar[i]);
//            tt1.push_back(ar[i]);
//            ret = max(ret, 1+GO(i+1, b+1, ar[i]));
//            tt1.pop_back();
//        }
//    }
//    for(i=b; i<m; i++)
//    {
//        if(ar[a]==br[i] and br[i]>prev)
//        {
//            //pf("%d ", ar[i]);
//            tt1.push_back(br[i]);
//            ret = max(ret, 1+GO(a+1, i+1, br[i]));
//            tt1.pop_back();
//        }
//    }
//    return mp[{a,{b,prev}}]=ret;
//}

void SHOW(int p)
{
    if(p==0)
    {
        return;
    }
    SHOW(path[p]);
    cout << br[p] << " " ;
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
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(n);
    for(i=1; i<=n; i++)
        takei(ar[i]);

    takei(m);
    for(i=1; i<=m; i++)
        takei(br[i]);

    //CLR1(path);

    for(i=1; i<=n; i++)
    {
        int tillnow = 0;
        for(j=1; j<=m; j++)
        {
            if(ar[i]==br[j])
            {
                ans[j] = 1 + ans[tillnow];
                path[j] = tillnow;
            }
            else if(ar[i]>br[j] and ans[j]>ans[tillnow])
            {
                tillnow = j;
            }
        }
    }
    k = 0;
    for(i=1; i<=m; i++)
    {
        if(k<ans[i])
        {
            j = i;
            k = ans[i];
        }
    }
    __(k);
//    deb(j, br[j]);
    if(k) SHOW(j);
    //if(k!=0) pf("%d", br[j]);
    NL;
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



