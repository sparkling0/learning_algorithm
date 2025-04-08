#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

// #define int long long 

const int N = 3e5 + 10;
int n, m;
int s[N], s1[N], s0[N];
int d[N];   // 差分
int l[N], r[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        cin >> l[i] >> r[i];
        d[l[i]] ++;
        d[r[i] + 1] --;
    }

    // 因为只考虑除去一次操作，只会有影响的是0和1
    for(int i = 1; i <= n; i ++)
    {
        s[i] = s[i - 1] + d[i];
        s1[i] = s1[i - 1], s0[i] = s0[i - 1];
        if(s[i] == 1) s1[i] ++;
        else if(s[i] == 0) s0[i] ++;
    }

    // 区间内1的数量，区间外0的数量
    for(int i = 1; i <= m; i ++)
    {   
        int res1 = s1[r[i]] - s1[l[i] - 1];
        int res0 = s0[r[i]] - s0[l[i] - 1];
        res0 = s0[n] - res0;
        cout << res0 + res1 << endl;
    }

    return 0;
    
}