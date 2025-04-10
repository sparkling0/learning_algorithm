#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 5e5 + 10;
int n, k;
int pre[N], ne[N], a[N];
priority_queue<PII, vector<PII>, greater<PII>> q;

void cut(int idx)
{
    if(ne[idx] != -1) 
    if(pre[idx] != -1) 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i ++)
    {
        ne[i] = (i + 1) < n ? (i + 1) : -1;
        pre[i] = (i - 1) >= 0 ? (i - 1) : -1;
    }

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        q.push({a[i], i});
    }

    while(k --)
    {
        auto t = q.top();
        q.pop();
        int x = t.first, idx = t.second;

        // 改值并删除
        if(ne[idx] != -1) 
        {
            a[ne[idx]] += x;
            q.push({a[ne[idx]], ne[idx]});
            pre[ne[idx]] = pre[idx];  
        }
        if(pre[idx] != -1) 
        {
            a[pre[idx]] += x;
            q.push({a[pre[idx]], pre[idx]});
            ne[pre[idx]] = ne[idx];
        }

        

        cut(idx);
    }

    while (q.size())
    {
        auto t = q.top();
        q.pop();

    }
    
}