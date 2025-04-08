#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e6 + 10;

int n, s, res;
int p[N], c[N];

bool check(int x)
{
    int sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(x <= c[i]) sum += p[i];
    }
    return s < sum;
}

signed main()
{
    cin >> n >> s;
    int m = 0;  // 最多集合训练几次
    for(int i = 1; i <= n; i ++)
    {
        cin >> p[i] >> c[i];
        m = max(m, c[i]);
    }

    int l = 0, r = m;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    
    for(int i = 1; i <= n; i ++) 
    {
        if(c[i] > l) res += p[i] * (c[i] - l );
    }
    res += s * l;

    cout << res << endl;
    
    return 0;
}