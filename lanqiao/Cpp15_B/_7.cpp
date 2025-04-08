#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define int long long 

const int N = 1e3 + 10;

int n, res = 0x3f3f3f3f;
int a[N], s[N];
priority_queue<int> q;

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for(int i = 2; i < n - 1; i ++)
    {
        for(int j = 1; i + j - 1 <= n; j ++)
        {
            q.push(s[j + i - 1] - s[j - 1]);
            // if(i == 2 && j == 4) cout << "4,5 " << s[j + i - 1] - s[j - 1] << endl;
            // if(i == 3 && j == 1) cout << "1,2,3 " << s[j + i - 1] - s[j - 1] << endl;
        }
    }

    int a = q.top();
    q.pop();

    while(q.size())
    {
        int b = q.top();
        q.pop();
        res = min(res, abs(a - b));
        a = b;
    }
    cout << res << endl;
    return 0;
}