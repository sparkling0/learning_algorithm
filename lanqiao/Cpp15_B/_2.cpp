#include <iostream>
#include <cmath>
using namespace std;

#define int long long

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lcd(int x, int y)
{
    int t = gcd(x, y);
    return x / t * y;
}

signed main()
{
    int x = lcd(343720, 15);
    int y = lcd(233333, 17);
    cout << x << " " << y << endl;
    cout << sqrt(4 * x * x + 4 * y * y);
    return 0;
}