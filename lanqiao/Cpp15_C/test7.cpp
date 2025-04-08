#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

// #define int long long 

const int N = 4e6 + 10;
int n, m;
int l[N], r[N];
int res;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        if(x > 0) r[x] ++;
        else if(x < 0) l[-x] ++;
        else res ++;
    }

    for(int i = 1; i <= m; i ++)
    {
        l[i] = l[i] + l[i - 1];
        r[i] = r[i] + r[i - 1];
    }

    int rmx = 0, lmx = 0;

    for(int i = 1; i <= m; i ++)    
    {
        // 向一个方向走 i 步后折返
        if(m > 2 * i)
        {
            rmx = max(rmx, r[i] + l[m - 2 * i]);
            lmx = max(lmx, l[i] + r[m - 2 * i]);
        }

        // 体力不够，走到底
        else 
        {
            rmx = max(rmx, r[2 * i]);
            lmx = max(lmx, l[2 * i]);
        }
    }

    res += max(rmx, lmx);

    cout << res << endl;

    return 0;
    
}