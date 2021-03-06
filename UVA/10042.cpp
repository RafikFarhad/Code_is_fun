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
#define takell(a)                                scanf("%lld", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
bool *p;
vector <int> prime;
int ss;
void SEIEVE()
{
    int i, j, l = sqrt(SIZE+5)+5;
    p = new bool[SIZE+5];
    for(i=2; i<l; i++)
    {
        if(p[i]==0)
        {
            prime.pb(i);
            for(j=i*i; j<SIZE; j+=i)
            {
                p[j] = 1;
            }
        }
    }
    for(i=l; i<SIZE; i++)
        if(!p[i])
            prime.pb(i);
    p[0]=p[1] = 1;

    ss = prime.size();
    return;
}

int COUNT(int a)
{
    int b = 0;
    while(a)
    {
        b+=(a%10);
        a/=10;
    }
    return b;
}

int PRIME(int a)
{
    int b = 0, i, l, j;
    for(i=0; i<ss and a>1; i++)
    {
        if(a%prime[i]==0)
        {
            l = 0;
            while(a%prime[i]==0)
            {
                a/=prime[i];
                l++;
            }
            b+=(COUNT(prime[i])*l);
        //    deb(prime[i], a);
        }
    }
    if(a>1) b+=COUNT(a);
    return b;
}

bool IS_PRIME(int a)
{
    if(a<100000)
    {
        return (!p[a]);
    }
    int i, j;
    for(i=0; i<ss; i++)
        if(a%prime[i]==0)
        {
            if(a/prime[i]>1)
                return false;
            return true;
        }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, n, l, t, keis=0;
    SEIEVE();
  //  deb(prime[0], prime[1], prime[2]);
   // deb(COUNT(4937775), PRIME(4937775));
  // deb(IS_PRIME(4875214), COUNT(4875214), PRIME(4875214));
    takei(t);
    while(t--)
    {
        takei(n);
        for(k=n+1; ; k++)
        {
            if(IS_PRIME(k)) continue;

            i = COUNT(k);
            j = PRIME(k);
           // deb(i, j);
            if(i==j)
            {
                pf("%d\n", k);
                break;
            }
        }
    }
    delete(p);

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


