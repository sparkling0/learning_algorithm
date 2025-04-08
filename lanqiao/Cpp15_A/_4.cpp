#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 10;
int n, k, t;
int res;
int a[N], b[N];

bool check(int x)
{
    for(int i = 1; i <= x; i ++) b[i] = a[i];
    sort(b + 1, b + n + 1);

    int s = 0, s2 = 0;
    // 初始窗口
    for(int i = 1; i < k; i ++)
    {
        s += b[i];
        s2 += b[i] * b[i];  
    }

    for(int i = 1; i + k - 1 <= x; i ++)
    {
        s -= b[i], s2 -= b[i] * b[i];
        s += b[i + k - 1], s2 += b[i + k - 1] * b[i + k - 1];

        if((s2 - k * s * s) < k * t) return true;
    }

    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> k >> t;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l;
    return 0;
}