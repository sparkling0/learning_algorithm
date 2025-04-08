#include <iostream>
using namespace std;

const int N = 20;

int n = 5;
bool st[N][N];
int row0[N], cow0[N], z0[N], f0[N];
int row1[N], cow1[N], z1[N], f1[N];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int ans;
int cur;

void dfs(int x, int y, int u)
{
    if(u == n * n) 
    {
        ans ++;
        return;
    }
    st[x][y] = true;
    row0[x] ++, cow0[y] ++;
    if(cur == 0) z0[x - y + n] ++, f0[x + y] ++;
    else z1[x - y + n] ++, f1[x + y] ++;

    for(int i = 0; i < 4; i ++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < n && !st[tx][ty])
        {
            
        }
    }
}

int main()
{
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}