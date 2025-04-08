#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;
int n, m;
string str[N];
int p[N];

struct Edge
{
    int a, b;
    int w;
    bool operator<(Edge other)
    {
        return w > other.w;
    }
}edge[N * N];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}


int cal(string a, string b)
{
    int res = 0;
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            int k = 0;
            while(k < m && a[(i + k) % m] == b[(j + k) % m])
                k ++;
            res = max(res, k);
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) p[i] = i;

    for(int i = 1; i <= n; i ++) cin >> str[i];
    int k = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = i + 1; j <= n; j ++)
        {
            edge[k ++] = {i, j, cal(str[i], str[j])};
        }
    }

    sort(edge, edge + k);

    int res = 0;

    for(int i = 0; i < k; i ++)
    {
        int x = edge[i].a, y = edge[i].b, w = edge[i].w;
        if(find(x) == find(y)) continue;
        res += w;
        p[find(x)] = find(y);
    }

    cout << res << endl;
    
    return 0;
}