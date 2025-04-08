#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int f[N][N];
int n, a, b;
int w[210];

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) cin >> w[i];

    for(int i = 1; i <= n; i ++)
    {
        for(int j = a; j >= 0; j --)
        {
            for(int k = b; k >= 0; k --)
            {
                if(j >= w[i]) f[j][k] = max(f[j][k], f[j - w[i]][k] + w[i]);
                if(k >= w[i]) f[j][k] = max(f[j][k], f[j][k - w[i]] + w[i]);
            }
        }
    }

    cout << f[a][b] << endl;
    return 0;
}