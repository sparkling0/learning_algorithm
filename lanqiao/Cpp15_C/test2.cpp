#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

#define int long long 

int res;
int n = 2000;
char a, b;
int pre, cur;
int k = 1;

signed main()
{
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b >> cur;
        if(a == b && cur - pre <= 1000) k ++; 
        else 
        {
            res = max(res, k);
            k = 1;
        }
        pre = cur;
    }
    cout << res << endl;
    return 0;
}