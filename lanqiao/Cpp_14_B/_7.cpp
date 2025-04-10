#include <iostream>
#include <cstring>
using namespace std;

#define int long long 

const int N = 5e5 + 10;
int k;
string s;
char c1, c2;
int res;

signed main()
{
    cin >> k;
    cin >> s >> c1 >> c2;

    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] != c1) continue;
        int j = i + k - 1;
        while(j < s.size())
        {
            if(s[j] == c2) res ++;
            j ++;
        }
    }
    cout << res << endl;
}