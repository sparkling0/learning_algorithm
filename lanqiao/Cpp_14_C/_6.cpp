#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
int n, m, a, b, res;
int g[N][N];

int main()
{
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> g[i][j];
        }
    }


    // 遍历框
    for(int i = 1; i + a - 1 <= n; i ++)
    {
        for(int j = 1; j + b - 1 <= m; j ++)
        {
            int tm = 2e9, tM = -1;
            for(int k = 0; k < a; k ++)
            {
                for(int h = 0; h < b; h ++)
                {
                    tm = min(tm, g[i + k][j + h]);
                    tM = max(tM, g[i + k][j + h]);
                }
            }
            res += tm * tM;
        }
    }

    cout << res << endl;    
    return 0;
}