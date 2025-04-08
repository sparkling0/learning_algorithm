#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> v[N];   // v[i] 表示以i为因数的答案
int cnt[N];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++) 
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    for(int i = 1; i <= N; i ++)    // 以i为约数
    {
        for(int j = i; j <= N; j += i)  // i 的倍数
        {
            if(cnt[j] >= 0)
            {
                for(int k = 0; k < cnt[j]; k ++)
                {
                    v[i].push_back(j); // 有cnt[j]个这样的宝石
                }
            }
        }
    }

    // 因为是从大到小遍历 gcd(a,b,c),先找到的一定是最大的
    for(int i = N; i >= 1; i --)
    {
        if(v[i].size() >= 3) 
        {
            // 字典序输出
            sort(v[i].begin(), v[i].end());
            for(int j = 0; j < 3; j ++) 
                cout << v[i][j] << " ";
            break;
        }
    }

    return 0;
}   