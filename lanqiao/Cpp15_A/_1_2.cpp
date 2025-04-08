#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 20;

int n = 5;
int ans;
int g[N][N];
int row0[N], cow0[N], z0[N], f0[N];
int row1[N], cow1[N], z1[N], f1[N];

void tran(int x)
{
    for(int i = 0; i < n * n; i ++)
    {
        g[i / n][i % n] = x & 1;
        x /= 2;
    }
}

int main()
{
    int M = pow(2, 25);
    
    for(int i = 0; i < M; i ++)
    {
        int bai = 0, hei = 0;
        memset(row0, 0, sizeof row0);
        memset(row1, 0, sizeof row1);
        memset(cow0, 0, sizeof cow0);
        memset(cow1, 0, sizeof cow1);
        memset(z0, 0, sizeof z0);
        memset(z1, 0, sizeof z1);
        memset(f0, 0, sizeof f0);
        memset(f1, 0, sizeof f1);
        memset(g, 0, sizeof g);
        tran(i);
        for(int j = 0; j < 5; j ++)
        {
            for(int k = 0; k < 5; k ++)
            {
                if(g[j][k] == 0) 
                {
                    row0[j] ++, cow0[k] ++;
                    z0[j - k + n] ++, f0[j + k] ++;
                    bai ++;
                }
                else
                {
                    row1[j] ++, cow1[k] ++;
                    z1[j - k + n] ++, f1[j + k] ++;
                    hei ++;
                }
            }
        }
        if(bai != 13 || hei != 12) continue;
        bool flag = true;
        for(int j = 0; j < 5; j ++)
        {
            if(row0[j] >= 5 || row1[j] >= 5 || cow0[j] >= 5 || cow1[j] >= 5) flag = false;
        }
        for(int j = 0; j < 10; j ++)
        {
            if(z0[j] >= 5 || z1[j] >= 5 || f0[j] >= 5 || f1[j] >= 5) flag = false;
        }
        if(flag) ans ++;
    }
    cout << ans;
    return 0;
}