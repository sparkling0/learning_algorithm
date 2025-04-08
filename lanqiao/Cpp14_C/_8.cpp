#include <iostream>
#include <stack>
using namespace std;

#define int long long

const int N = 3e5 + 10;
int a[N];
int n, res;
int r[N], l[N]; // 左右最近比自己小的数的位置
stack<int> s1, s2;

signed main()
{
    cin >> n;
    for(int i = 1; i <= n ; i ++) cin >> a[i];
    a[0] = a[n + 1] = -1;

    // 左边第一个比自己小的数
    for(int i = 0; i <= n; i ++)
    {
        while (s1.size() && a[s1.top()] >= a[i])
        {
            s1.pop();
        }
        if(s1.empty()) l[i] = 0;
        else l[i] = s1.top();
        s1.push(i);
    }

    // 右边第一个比自己小的数
    for(int i = n + 1; i >= 0; i --)
    {
        while (s2.size() && a[s2.top()] >= a[i])
        {
            s2.pop();
        }
        if(s2.empty()) r[i] = n;
        else r[i] = s2.top();
        s2.push(i);
    }

    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        int t = a[i] * (r[i] - l[i] - 1);
        res = max(res, t);
    }

    cout << res << endl;
    return 0;
}