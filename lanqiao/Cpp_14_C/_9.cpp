#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++)
    {
        for(int j = i + 1; j <= n; j ++)
        {
            if(gcd(a[i],a[j]) != 1)
            {
                cout << i << " " << j << endl;
                return 0;    
            }
        }
    }
    return 0;
}