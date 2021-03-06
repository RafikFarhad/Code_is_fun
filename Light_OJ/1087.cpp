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
#define csi                                     pf("Case %d:", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 150005
int tree[4*SIZE+7], start, last, n, val, ar[4*SIZE];
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = 0;
        ar[node] = -1;
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
void UPDATE(int i, int j, int node)
{
    if(i>start || j<start) return;
    if(i==j)
    {
        tree[node] = 1;
        ar[node] = val;
        //deb(node, i);
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] = tree[left]  + tree[right];// + prop[node] * (j-i+1);
    return;
}
int QUERY(int i, int j, int node, int carry)
{
    //if(i>last || j<start) return 0;
    if(i==j)
    {
        int a = ar[node];
        tree[node] = 0;
        ar[node] = -1;
        return a;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int a;
    if(tree[left]>=carry)
    {
        a = QUERY(i, mid, left, carry);
    }
    else
    {
        a = QUERY(mid+1, j, right, carry-tree[left]);
    }
    tree[node] = tree[left]  + tree[right];
    return a;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, m;
    char pp;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(k);
        m = n+k;
        CLR(tree);
        CLR(ar);
        INIT(1, m, 1);
        last = 0;
        for(i=0; i<n; i++)
        {
            takei(val);
            last++;
            start = last;
            UPDATE(1, m, 1);
        }
        csi;NL;
        for(i=0; i<k; i++)
        {
            getchar();
            sf("%c %d", &pp, &a);
            //deb(pp, a);
            if(pp=='a')
            {
                last++;
                start = last;
                val = a;
                UPDATE(1, m, 1);
            }
            else
            {
                a = QUERY(1, m, 1, a);
                a==-1?pf("none\n"):pf("%d\n", a);

                //if()
            }
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



