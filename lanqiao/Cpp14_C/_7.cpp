#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e3 + 10;
int h[N][N];
bool st[N][N];
int n;

struct node
{
    int x, y;
    int time;
};


void bfs()
{
    queue<node> q;
    q.push({0,0,0});

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int x = t.x, y = t.y;
        int time = t.time;

        if(x == n - 1 && y == n - 1)
        {
            cout << time << endl;
            return;
        }

        // 注意这个东西
        if(st[x][y]) continue;
        st[x][y] = true;

        if(x + 1 < n && !st[x + 1][y]) q.push({x + 1, y, time + 1});
        if(y + 1 < n && !st[x][y + 1]) q.push({x, y + 1, time + 1});
        int cur = h[x][y];
        for(int i = y + 1; i < n; i ++)
        {
            if(cur > h[x][i])
            {
                q.push({x, i, time + 1});
                cur = h[x][i];
            }
            else break;
        }
    }
    
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cin >> h[i][j];
        }
    }

    bfs();
}