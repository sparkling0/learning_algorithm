#include <iostream>
#include <cstring>
using namespace std;

#define int long long

int t;

signed main()
{
    cin >> t;
    while (t--)
    {
        int i = 0, ic = 0, icp = 0, icpc = 0;
        int len;
        string str;
        cin >> len;
        cin >> str;
        for (int j = 0; j < len; j++)
        {
            if (str[j] == 'i' || str[j] == 'I')
                i++;
            if (str[j] == 'c' || str[j] == 'C')
            {
                ic += i;
                icpc += icp;
            }
            if (str[j] == 'p' || str[j] == 'P')
                icp += ic;
        }
        cout << icpc << endl;
    }
    return 0;
}