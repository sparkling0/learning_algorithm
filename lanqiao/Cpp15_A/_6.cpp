#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e4 + 10;
int n, q;
int res;
int c[N];
bool g[N][N];
int dist[N][N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> q;
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 1; i < n; i ++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(g[i][j]) dist[i][j] = c[i] + c[j];
            // else dist[i][j] = -2e9;
            for(int k = 1; k <= n; k ++)
            {
               // if(i == 1 && j == 3) cout << "k = " << k << " " << dist[i][j] << endl;
                dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j] - c[i]);
            }
        }
    }

    // for(int i = 1; i <= n; i ++)
    // {
    //     for(int j = 1; j <= n; j ++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(q --)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }

    return 0;
}