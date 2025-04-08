#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// #define int long long 
typedef pair<int, int> PII;

const int N = 15;
int n, k;
vector<int> ans;
int g[N][N];
bool st[N][N];
bool point[N * 2][N * 2];

int Dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int Dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dfs(int x, int y)
{
    st[x][y] = true;
    if(x == n - 1 && y == n - 1)
    {
        if(ans.size() == n * n - 1) return true;
        else return false;
    }

    for(int i = 0; i < 8; i ++)
    {
        int dx = x + Dx[i], dy = y + Dy[i];
        int px = x + dx, py = y + dy;
        if(dx >= 0 && dx < n && dy >= 0 && dy < n && !st[dx][dy] && !point[px][py] && g[dx][dy] == ((g[x][y] + 1) % k))
        {
            st[dx][dy] = true;
            point[px][py] = true;
            ans.push_back(i);
            if(dfs(dx, dy)) 
            {
                return true;
            }
            ans.pop_back();
            point[px][py] = false;
            st[dx][dy] = false;
        }
    }

    return false;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cin >> g[i][j];
        }
    }

    if(dfs(0, 0)) 
    {
       for(int it : ans) cout << it;
    }
    else cout << -1;
        

    return 0;
}