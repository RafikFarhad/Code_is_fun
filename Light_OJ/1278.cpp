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
#define _(o)                                    pf("%d", o)

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
#define SIZE 40000000
long long pr[2433654+100], cow;
int p[SIZE/32+10];

void SEIEVE()
{
    long long i, j;
    //for(i=4; i<SIZE(); i+=2) p[i] = 1;
    cow = 0ll;
    pr[cow++] = 2ll;
    for(i=3; i<SIZE; i+=2)
    {
        if(!(p[i/32]&(1<<(i%32))))
        {
            //if(i%10001==0) deb(i, cow, i*i);
            pr[cow++] = i;
            for(j=i*i; j<SIZE; j+=i)
                p[j/32]|=(1<<(j%32));
        }
    }
    /*
    ok
    for(i=0; i<25; i++)
        deb(pr[i]);
    deb(cow);*/
}

/// the main idea is to find the odd divisor of n. explanation here http://light-online-judge.blogspot.com/2013/02/solution-of-light-online-judge-1278-sum.html

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k, l, t, keis=0, n, ans;
    SEIEVE();
    takell(t);
    while(t--)
    {
        takell(n);
        ans = 1;
        while(n%2ll==0)
            n/=2ll;
        for(i=1; i<cow and n!=1; i++)
        {
            if(n%pr[i]==0)
            {
                k = 1;
                while(n%pr[i]==0)
                {
                    n/=pr[i];
                    k++;
                }
                ans*=k;
            }
        }
        if(n!=1) ans <<= 1;
        csll;
        pf("%lld\n", ans-1);

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


