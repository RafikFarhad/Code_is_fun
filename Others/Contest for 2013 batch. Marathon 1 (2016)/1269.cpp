///Only Sakibul Mowla vai is real :P



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
#define SIZE 50005

class DATA
{
public:
    int ar[3];
    DATA()
    {
        CLR1(ar);
    }
};

vector <DATA> tree;
int n, ans1, ans2, current;
void ADD(int root, int num, int pos)
{
    if(pos==-1) return;
    int k = (num>>pos) & 1;
    if(tree[root].ar[k]==-1)
    {
        tree.pb(DATA());
        tree[root].ar[k] = current;
        current++;
    }
    ADD(tree[root].ar[k], num, pos-1);
    return;
}

int FIND_MAX(int num)
{
    int i, root=0, k, ans=0;
    for(i=31; i>=0; i--)
    {
        k = (num>>i) & 1;
        k ^= 1;
        if(tree[root].ar[k]==-1)
        {
            ans <<= 1;
            root = tree[root].ar[k^1];
        }
        else
        {
            ans <<= 1;
            ans++;
            root = tree[root].ar[k];
        }
    }
    return ans;
}

int FIND_MIN(int num)
{
    int i, root=0, k, ans=0;
    for(i=31; i>=0; i--)
    {
        k = (num>>i) & 1;
        //k ^= 1;
        if(tree[root].ar[k]==-1)
        {
            ans <<= 1;
            ans++;
            root = tree[root].ar[k^1];
        }
        else
        {
            ans <<= 1;
            //ans++;
            root = tree[root].ar[k];
        }
    }
    return ans;
}



int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int t;
    takei(t);
    while(t--)
    {
        takei(n);
        tree.clear();
        tree.pb(DATA());
        ans1 = 0;
        ans2 = 1<<29;
        c = 0;
        current = 1;
        ADD(0, 0, 31);
        for(i=0; i<n; i++)
        {
            takei(b);
            c = c^b;
            ans1 = max(ans1, FIND_MAX(c));
            ans2 = min(ans2, FIND_MIN(c));
            ADD(0, c, 31);
        }
        csi;
        pf("%d %d\n", ans1, ans2);

    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

