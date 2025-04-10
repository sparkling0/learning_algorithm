#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int N = 1e6 + 10;
int n;
string str;
int res;

int main()
{
    cin >> str;
    for(int i = 0; i < str.size() - 1; i ++)
    {
        if(str[i] == str[i + 1] || str[i] == '?' || str[i + 1] == '?')
        {
            res ++;
            i ++;   // 跳过这一个
        }
    }
    cout << res << endl;
    return 0;
}