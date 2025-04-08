#include<iostream>
using namespace std;

string num[] = 
{
    "1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011"
};

int cal(string s)
{
    int res = 0;
    for(int i = 0; i < 10; i ++)
    {
        bool flag = true;
        for(int j = 0; j < 7; j ++)
        {
            if(s[j] == '1' && num[i][j] == '0')
            {
                flag = false;
                break;
            }
        }
        if(flag) res ++;
    }
    return res;
}

int main()
{
    int res = 1;
    for(int i = 0; i < 18; i ++)
    {
        string s;
        cin >> s;
        res *= cal(s);
    }

    cout << res << endl;
    return 0;
}