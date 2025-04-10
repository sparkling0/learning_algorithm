#include <iostream>
#include <map>
using namespace std;

const int N = 1e4 + 10;
int n;
int a[N], b[N];
int res1, res2;

bool checkmin(int x)
{
    for(int i = 0; i < n; i ++)
        if(a[i] / x > b[i])
            return false;
    
    return true;
}

bool checkmax(int x)
{
    for(int i = 0; i < n; i ++)
        if(a[i] / x < b[i])
            return false;
    
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i] >> b[i];

    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if(checkmin(mid)) r = mid;
        else l = mid + 1;
    }
    res1 = l;

    l = 1, r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(checkmax(mid)) l = mid;
        else r = mid - 1;
    }
    res2 = l;
    
    cout << res1 << " " << res2 << endl;
}