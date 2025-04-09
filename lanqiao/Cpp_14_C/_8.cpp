#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, res = -1;
int s[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        s[i] ^= s[i - 1];
    }

    for(int i = 1; i < n; i ++)
    {
        for(int j = i; j < n; j ++)
        {
            for(int k = j + 1; k < n; k ++)
            {
                for(int h = k; h <= n; h ++)
                {
                    int x = s[j] ^ s[i - 1];
                    int y = s[h] ^ s[k - 1];
                    res = max(res, abs(y - x));
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}