/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};
char adj[105][105];
int r, c;

void DFS(int i, int j)
{
    if(i<0 || j<0 || i==r || j==r || adj[i][j]=='.') return;
    adj[i][j] = '.';
    for(int po=0; po<8; po++)
        DFS(i+xx[po], j+yy[po]);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11953.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, i, j, k, keis=0;
    sf("%d ", &t);
    while(t--)
    {
        sf("%d ", &r);
        for(i=0; i<r; i++)
            gets(adj[i]);
        int cow = 0;

        for(i=0; i<r; i++)
        {
            for(j=0; j<r; j++)
            {
                if(adj[i][j]=='x')
                {
                    cow++;
                    DFS(i, j);
                }
            }
        }
        pf("Case %d: %d\n", ++keis, cow);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
