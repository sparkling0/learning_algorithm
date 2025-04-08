#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 2e5 + 10;
int n, m;
int res;

int h1[N], e1[N], ne1[N], idx1, val1[N], root1; 
int h2[N], e2[N], ne2[N], idx2, val2[N], root2;
bool st1[N], st2[N];

void add1(int a, int b)
{
    e1[idx1] = b;
    ne1[idx1] = h1[a];
    h1[a] = idx1 ++;
    if(b == 1) root1 = idx1;
}

void add2(int a, int b)
{
    e2[idx2] = b;
    ne2[idx2] = h2[a];
    h2[a] = idx2 ++;
    if(b == 1) root2 = idx2;
}

int dfs(int x, int y)
{
    if(val1[x] != val2[y]) return 0;

    int res = 0;
    for(int i = h1[x]; i != -1; i = ne1[i])
    {
        for(int j = h2[y]; j != -1; j = ne2[j])
        {
            int t1 = e1[i], t2 = e2[j];
            if(!st1[t1] || !st2[t2]) continue;
            if(val1[t1] == val2[t2]) 
            {   
                st1[t1] = st2[t2] = true;
                res = max(res, dfs(t1, t2));
            }
        }
    }
    return res + 1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    memset(h1, -1, sizeof h1);
    memset(h2, -1, sizeof h2);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> val1[i];
    for(int i = 1; i <= m; i ++) cin >> val2[i];

    for(int i = 0; i < n - 1; i ++) 
    {
        int a, b;
        cin >> a >> b;
        add1(a, b);
        add1(b, a);
    }

    for(int i = 0; i < m - 1; i ++) 
    {
        int a, b;
        cin >> a >> b;
        add2(a, b);
        add2(b, a);
    }

    st1[1] = st2[1] = true;
    res = dfs(root1, root2);

    cout << res << endl;
    
    return 0;
}