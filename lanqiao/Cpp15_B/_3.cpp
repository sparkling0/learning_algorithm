#include <iostream>
#include <vector>
using namespace std;

#define int long long 

int n, res;

bool check(int x)
{
    int is_odd = 1;    // 默认奇数
    while(x > 0)
    {
        int t = x % 10;
        if((t % 2) != is_odd) return false;
        is_odd ^= 1;
        x /= 10;
    }
    return true;
}

int cal(int x)
{
    int cnt = 0;
    for(int i = 1; i <= x; i ++)
    {
        if(check(i))
        {
            cnt ++;
        }
    }
    return cnt;
}

signed main()
{
    cin >> n;
    // for(int i = 1; i <= n; i ++) 
    // {
    //     cout << cal(i) << endl;
    // }
    cout << cal(n) << endl;
    return 0;
}