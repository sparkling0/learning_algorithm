#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

const int N = 1e5 + 10;
int n;
int yz_x[N], xz_y[N], xy_z[N];
int x[N], y[N], z[N];

signed main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> x[i];
    for(int i = 0; i < n; i ++) cin >> y[i];
    for(int i = 0; i < n; i ++) cin >> z[i];
    for(int i = 0; i < n; i ++)
    {
        yz_x[i] = y[i] + z[i] - x[i];
        xz_y[i] = x[i] + z[i] - y[i];
        xy_z[i] = x[i] + y[i] - z[i];
    }
    sort(yz_x, yz_x + n);
    sort(xz_y, xz_y + n);
    sort(xy_z, xy_z + n);

    // X 胜
    int res = -1;
    int s = 0, i;
    for(i = 0; i < n; i ++)
    {
        s += yz_x[i];
        if(s >= 0) break;
        else res = max(res, i + 1);
    }

    // Y 胜
    s = 0;
    for(i = 0; i < n; i ++)
    {
        s += xz_y[i];
        if(s >= 0) break;
        else res = max(res, i + 1);
    }

    // Z 胜
    s = 0;
    for(i = 0; i < n; i ++)
    {
        s += xy_z[i];
        if(s >= 0) break;
        else res = max(res, i + 1);
    }

    cout << res << endl;
    return 0;
}