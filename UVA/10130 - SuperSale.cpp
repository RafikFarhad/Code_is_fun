/// Heil Hydra
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;} template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 1005
int n, cap, weight[SIZE], cost[SIZE], man;
int DDPP[SIZE][35];

int DO(int start, int wet)
{
    if(start==n) return 0;
    if(DDPP[start][wet] !=-1) return DDPP[start][wet];
    int profit1=0, profit2=0;
    if(wet+weight[start]<=cap)
        profit1 = cost[start] + DO(start+1, wet+weight[start]);
    profit2 = DO(start+1, wet);
    //deb(start, cost[start], wet, profit1);
    return DDPP[start][wet] = max(profit1, profit2);
    //return DDPP[start][wet];
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j, a, b, c;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            takei(cost[i]);
            takei(weight[i]);
        }
        takei(man);
        a = 0;
        for(i=0; i<man; i++)
        {
            CLR1(DDPP);
            takei(cap);
            a += DO(0, 0);
        }
        pf("%d\n", a);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
