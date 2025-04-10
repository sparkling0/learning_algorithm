#include <iostream>
#include <cstring>
using namespace std;

const int N = 15;
int n;
bool st[N];

struct Plane
{
    int t, d, l;
}p[N];

bool dfs(int k, int endt)
{
    if(k == n) return true;

    for(int i = 0; i < n; i ++)
    {
        // 没有起飞 && 可以在endt之后起飞
        if(!st[i] && (p[i].t + p[i].d) >= endt)
        {
            // 紧接起飞，注意看下是否可以紧接
            st[i] = true;
            if(dfs(k + 1, max(endt, p[i].t) + p[i].l)) return true;
            st[i] = false;
        }
    }
    
    // 遍历都没结束，那就是不行
    return false;
}


int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        cin >> n;
        bool flag = false;
        memset(st, false, sizeof st);
        for(int i = 0; i < n; i ++) cin >> p[i].t >> p[i].d >> p[i].l;

        for(int i = 0; i < n; i ++)
        {
            st[i] = true;
            int endt = p[i].t + p[i].l; // 最早起飞
            
            if(dfs(1, endt)) 
            {
                flag = true;
                break;
            }
            st[i] = false;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    
}