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
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
#define SIZE 1003
bool prime[SIZE];
void SEIEVE()
{
    long long unsigned i, j, lim = sqrt(SIZE) + 1;
    for(i=2; i<=lim ; i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<SIZE; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
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
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, ar[27] = {0};
    bool taken[10003] = {false};
//    char pp[100];
//    fgets(pp, 100, stdin);
    SEIEVE();
    string pp;
    cin >> pp;

    pp = "0" + pp;
    l = pp.size();
    //deb(pp, l);
    for(i=0; i<l; i++)
    {
        ar[pp[i]-'a']++;
    }
    vector <pair< int, int> > in;
    for(i=0; i<26; i++)
    {
        if(ar[i]) in.pb({ar[i], i});
    }
    a = 1;
    bool os[10003] = {false};
    //deb(l);
    for(i=2; i<l; i++)
    {
        if(!prime[i] and i+i>l-1)
        {
            a++;
            //deb(i);
        }
        else
        {
            os[i] = 1;
        }
    }
    os[1] = 1;
    //deb(os[3]);
    a = l-1-a;
//    deb(a);
    sort(all(in));
    //deb(in.size());
//    deb(l, a, in[in.size()-1].xx);
//    for(auto s:in)
//    {
//        deb(s.xx, s.yy);
//    }
    pp = "";
    pp.assign(l, '#');
    if(a>in[in.size()-1].xx)
    {
        puts("NO");
    }
    else
    {
        for(i=2; i<l; i++)
        {
            if(os[i] and in[in.size()-1].xx)
            {
                //deb("-->", i);
                taken[i] = 1;
                pp[i] = (char)(in[in.size()-1].yy+'a');
                in[in.size()-1].xx--;
            }
        }
        for(j=0; j<in.size();j++)
        {
            if(in[j].xx)
            {
                in[j].xx--;
                pp[1] = (char)(in[j].yy+'a');
                //ok deb((char)in[j].yy+'a');
                taken[1] = 1;
                break;
            }
        }
        //deb(pp);
        for(i=2; i<l; i++)
        {
            if(!taken[i])
            {
                //deb(i);
                for(j=0; j<in.size();j++)
                {
                    //deb(in[j].xx, in.size());
                    if(in[j].xx)
                    {
                        in[j].xx--;
                        pp[i] = (char)(in[j].yy+'a');
                        taken[i] = 1;
                        break;
                    }
                }
            }
        }
        cout << "YES\n" << pp.c_str()+1 << endl;
    }



    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


