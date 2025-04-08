#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 1e5 + 10;
int n, res;
int a[N], f[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> f[i];

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(i == j || f[i] == j || f[j] == i) continue;
            res = max(res, a[i] ^ a[j]);
        }
    }
    
    cout << res << endl;
    return 0;
}