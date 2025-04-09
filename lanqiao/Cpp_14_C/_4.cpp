#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int N = 1e6 + 10;
int n;
string str;

int count(string s)
{
    int res = 0;
    for(int i = 0; i < s.size();)
    {
        int j = i + 1;
        while(j < s.size() && s[j] == s[i]) j ++;
        res += (j - i) / 2;
        i = j;
    }
    return res;
}

int main()
{
    cin >> str;
    // int pos = str.find("?"); // 不知道为啥蓝桥杯官网这里运行错误
    int pos = 0;
    for(int i = 0; i < str.size(); i ++)
    {
        if(str[i] == '?')
        {
            pos = i;
            break;
        }
    }
    string s0 = str;
    string s1 = str;
    s0[pos] = '0';
    s1[pos] = '1';

    int res = max(count(s0), count(s1));

    cout << res << endl;
    return 0;
}