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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}


int main()
{
    //time_t t1=clock();
    freopen("12592.txt", "r", stdin);

    ///                                    MAIN
    string a, b;
    map <string, string> ko;
    int n;
    sf("%d ", &n);
    while(n--)
    {
        getline(cin, a);
        getline(cin, b);
        ko[a] = b;
    }

    sf("%d ", &n);
    while(n--)
    {
        getline(cin, a);
        cout << ko[a] << endl;
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


