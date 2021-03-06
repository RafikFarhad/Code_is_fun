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
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0;
    int den, num, ar[1009];
    vector <int> v;
    while(sf("%d%d", &num, &den)==2 and num+den)
    {
        CLR(ar);
        v.clear();
        k = 1;
        i = num;
        j = den;
        ar[i] = k;
        while(1)
        {
            t = -1;
            if(!i) break;
            i*=10;
//            while(i<j)
//            {
//                i*=10;
//                t++;
//                if(t)
//                {
//                    v.pb(0);
//                    k++;
//                    //ar[i] = k;
//                }
//            }
            //deb(i, j);
            l = i/j;
            i = i%j;
            v.pb(l);
            if(!i or ar[i] or k>(2*den)) break;
            ar[i] = ++k;
        }
        if(!i)
        {
            pf(".");
            for(auto i:v)
                pf("%d", i);
            puts("\nThis expansion terminates.\n");
        }
        else
        {
            pf(".");
            for(j=0; j<v.size(); j++)
            {
                //if(j==49) NL;
                if(j and (j+1)%50==0 and (j+1)!=49) NL;
                pf("%d", v[j]);
            }
            NL;
            //deb("---", k-ar[i]+1);
            pf("The last %d digits repeat forever.\n\n", 1+k-ar[i]);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

