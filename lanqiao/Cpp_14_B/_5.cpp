#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n;
int f[N];
string a[N];
int res;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j ++)
        {
            if(a[j].back() == a[i][0]) f[i] = max(f[i], f[j] + 1);
        }
    }

    res = n - f[n];
    cout << res << endl;
}