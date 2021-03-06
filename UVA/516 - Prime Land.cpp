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
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define all(o)                                      o.begin(), o.end()
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long  long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 300000
bool *p;
vector <long long> prime;
long long ss;
void SEIEVE()
{
    long long i, j, l = sqrt(SIZE)+10;
    p = new bool[SIZE];
    for(i=2; i<l; i++)
    {
        if(!p[i])
        {
            prime.pb(i);
            for(j=i*i; j<SIZE; j+=i)
                p[j] = 1;
        }
    }
    for(i=l+1; i<SIZE; i++)
        if(!p[i])
            prime.pb(i);
    ss = prime.size();
    //deb(ss, l, prime[ss-1]);
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long n, i, j, k, l, t, keis=0, sq;
    vector <int> v;
    SEIEVE();
    char pp[1000];
    while(gets(pp))
    {
        if(strlen(pp)==1 and pp[0] == '0') break;
        l = strlen(pp);
        v.clear();
        k = 0;
        for(i=0; i<l; i++)
        {
            if(pp[i]==' ')
            {
                if(k) v.pb(k);
                k = 0;
            }
            else
            {
                k = k*10+pp[i]-'0';
            }
        }
        if(k) v.pb(k);
        for(k=1, i=0; i<v.size()-1; i+=2)
            k *= POOW(v[i], v[i+1]);
        k--;
        //deb(k);
        vector < pair<long long, long long> > vv;
        vv.clear();

        for(i=0; i<ss and k>1; i++)
        {
            if(k%prime[i]==0)
            {
                //deb(i, prime[i]);
                l = 0;
                while(k%prime[i]==0)
                {
                    k/=prime[i];
                    l++;
                }
                vv.pb({prime[i], l});
            }
        }
        if(k>1) vv.pb({k, 1});
        sort(all(vv));
        reverse(all(vv));
        for(i=0; i<vv.size(); i++)
        {
            if(!i) pf("%lld %lld", vv[i].first, vv[i].second);
            else pf(" %lld %lld", vv[i].first, vv[i].second);
        }
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

