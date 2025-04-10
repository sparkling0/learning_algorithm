// acwing 被卡掉一个数

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        string t, s;
        int res = 0;
        cin >> t >> s;
        for(int i = 0; i < t.size(); i ++)
        {
            if(t[i] != s[i])
            {
                if(i - 1 >= 0 && i + 1 < t.size() && s[i - 1] == s[i + 1]) 
                {
                    res ++;
                    s[i] = t[i];
                }
                else 
                {
                    res = -1;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    
    return 0;
}