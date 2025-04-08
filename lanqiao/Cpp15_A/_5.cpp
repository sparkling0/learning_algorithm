#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 10;
int n, m;
int res;
int a[N];

vector<pair<int, int>> ans;
vector<int> pos[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            for(int k = 1; k <= n; k ++)
            {
                for(int h = 1; h <= n; h ++)
                {
                    if(i == j || i == k || i == h || j == k || j == h || k == h) continue;
                    if(a[j] % a[i] == 0 && a[h] % a[k] == 0) res ++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}