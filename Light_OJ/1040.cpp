/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 46400
int n, par[55];

class DATA
{
public:
    int u, v, w;
    DATA(int _u, int _v, int _w) :u(_u), v(_v), w(_w)
    {

    }
    bool operator < (const DATA a) const
    {
        return a.w > w;
    }
};

void INIT()
{
    for(int i =0; i<n; i++)
        par[i] = i;
        return;
}

int CHECK_PAR(int k)
{
    if(par[k] == k) return k;
    return par[k] = CHECK_PAR(par[k]);
}
void JOIN(int x, int y)
{
    par[x] = y;
    return;
}

int MST(vector<DATA> p)
{
    int po = p.size(), i, u, v, w, cow = 0, total = 0, x, y;
    if(n-1==cow) return total;
    for(i=0; i<po; i++)
    {
        u = p[i].u;
        v = p[i].v;
        w = p[i].w;
        x= CHECK_PAR(u);
        y = CHECK_PAR(v);
        if(x!=y)
        {
            cow++;
            total+=w;
            JOIN(x, y);
            if(n-1==cow) return total;
        }
    }
    return -55;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k, all;
    vector <DATA> v;
    takei(t);
    while(t--)
    {
        all = 0;
        v.clear();
        takei(n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
        {
            takei(k);
            if(k)
            {
                v.pb(DATA(i, j, k));
                all+=k;
            }
        }
        sort(v.begin(), v.end());
        INIT();
        k = MST(v);
        if(k<0) pf("Case %d: -1\n", ++keis);
        else pf("Case %d: %d\n", ++keis, all-k);

        /*for(i=0; i< v.size(); i++)
            deb(v[i].w);
        cout << endl;*/
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
