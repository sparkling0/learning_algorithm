#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

const int N = 1e5 + 10;
int n;

int main()
{
    cin >> n;
    while(n --)
    {
        string str;
        cin >> str;
        int l = -1, r = str.size() - 1;
        for(int i = 0; i < str.size(); i ++)
        {
            if(str[i] != 'l' && str[i] != 'q' && str[i] != 'b')
            {
                l = i;
                break;
            }
        }

        if(l == -1) 
        {
            puts("Yes");
            continue;
        }

        for(int i = str.size() - 1; i >= 0; i --)
        {
            if(str[i] != 'l' && str[i] != 'q' && str[i] != 'b')
            {
                r = i;
                break;
            }
        }

        string tmp = str.substr(l, r - l + 1);
        reverse(tmp.begin(), tmp.end());

        if(str.substr(l, r - l + 1) != tmp) puts("No");
        else if(str.substr(0, l) != str.substr(r + 1, l)) puts("No");
        else puts("Yes");
    }
    
    return 0;
}