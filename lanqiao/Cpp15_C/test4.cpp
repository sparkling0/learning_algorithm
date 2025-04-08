#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
using namespace std;

#define int long long 

const int N = 2e5 + 10;
int s[] = {1,0,0,0,1,0,1,0,2,1};

struct num
{
    int cnt;
    int v;
    bool operator<(num other)
    {
        if(cnt != other.cnt) return cnt < other.cnt;
        else return v < other.v;
    }
}p[N];
int n;

int cal(int x)
{
    int t = 0;
    while(x > 0)
    {
        t += s[x % 10];
        x /= 10;
    }
    return t;
}

signed main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) 
    {
        int x;
        cin >> x;
        p[i] = {cal(x), x};
    }
    sort(p, p + n);
    for(int i = 0; i < n; i ++) cout << p[i].v << " ";
    return 0;
}