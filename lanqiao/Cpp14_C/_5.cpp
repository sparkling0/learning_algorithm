#include <iostream>
using namespace std;

const int N = 1e4;

const int Mod = 998244353;

int n, m;
int f[N][N];

int main()
{
    cin >> n >> m;
    int res = 1;

    for(int i = 0; i <= n - 4 * m + 1; i ++)
        for(int j = 0; j <= i; j ++)
            if(!j) f[i][j] = 1;
            else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % Mod;

    for(int i = 0; i < n - 4 * m; i ++)
    {
        res = res * 10 % Mod;
    }

    res = res * f[n - 4 * m + 1][m] % Mod;

    cout << res << endl;

    return 0;
}