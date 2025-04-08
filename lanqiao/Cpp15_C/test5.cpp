#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

// #define int long long 

const int N = 1e5 + 10;
int n;
int a[N], d[N];
int res;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int j = 1;
    for(int i = 1; i <= n / 2; i ++) d[i] = a[n - i + 1] - a[i];

    for(int i = 1; i <= n / 2; i ++)
    {
        res += abs(d[i]);
        if(d[i] * d[i + 1] <= 0) continue;
        else if(d[i] > 0)
        {
            d[i + 1] = max(d[i + 1] - d[i], 0);
        }
        else 
        {
            d[i + 1] = min(d[i + 1] - d[i], 0);
        }
    }
    cout << res << endl;
    return 0;
}