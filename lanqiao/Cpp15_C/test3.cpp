#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

#define int long long 

const int N = 1e6;

int n;
bool st[N];
int res;

// 1 ~ x 求和公式
int sum(int x)
{
    return (1 + x) * x / 2;
}

signed main()
{
    // 打表找规律, i ~ j 间的和
    for(int i = 1; i < 1000; i ++)
    {
        for(int j = i + 1; j < 1000; j ++)
        {
            int x = sum(j) - sum(i - 1);
            st[x] = true;
        }
    }
    for(int i = 2; i < 1000; i ++)
        if(!st[i]) cout << i << " ";

    // 筛除 2的幂,2的幂二级制只有一个1（除1外），减去1后全是1（这个1也可以筛除，因此不用特判）,变为反码
    // cin >> n;
    // for(int i = 0; i < n; i ++)
    // {
    //     int x;
    //     cin >> x;
    //     if(x & (x - 1) == 0) res ++;
    // }

    // cout << res << endl;
    return 0;
}