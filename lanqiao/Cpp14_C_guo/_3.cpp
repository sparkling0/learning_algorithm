#include <iostream>
using namespace std;

int n;

int sum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    cin >> n;
    int res = 0;
    while (n)
    {
        res ++;
        n -= sum(n);
    }
    cout << res << endl;
    return 0;
}