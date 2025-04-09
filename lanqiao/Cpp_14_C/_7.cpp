#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1e5 + 10, MOD = 998244353;
int a, b;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> a >> b;
    int p = pow(a, b);

    int res = 1;
    for(int i = 2; i < p; i ++)
    {
        if(gcd(i, p) != 1) res = (res + 1) % MOD;
    }

    cout << res << endl;
    return 0;
}