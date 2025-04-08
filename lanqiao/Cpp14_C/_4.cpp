#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define int long long

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

vector<int> count(string s, int M)
{
    vector<int> res;

    if(s == "*") 
    {
        if(M == 59 || M == 23) res.push_back(0);
        for(int i = 1; i <= M; i ++)
            res.push_back(i);
    }
    else
    {
        int pre = -1, cur = 0;
        for(auto c : s)
        {
            if(c == ',')
            {
                if(cur <= M) res.push_back(cur);
                cur = 0;
            }
            else if(c == '-')
            {
                pre = cur;
                cur = 0;
            }
            else 
            {
                cur = cur * 10 + (c - '0');
            }
        }

        if(pre != -1)
        {
            for(int i = pre; i <= min(cur,M); i ++)
                res.push_back(i);
        }
        else res.push_back(cur);
    }

    return res;
}

signed main()
{
    string S,M,H,D,Mon;
    cin >> S >> M >> H >> D >> Mon;
    int cday = count(S,59).size() * count(M,59).size() * count(H,23).size();

    int ans = 0;
    auto mons = count(Mon,12);
    for(auto mon : mons)
    {
        ans += count(D,month[mon - 1]).size() * cday;
    }
    cout << ans << endl;
    return 0;
}