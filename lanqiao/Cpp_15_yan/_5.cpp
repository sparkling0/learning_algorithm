#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m, t;
vector<PII> r, c;
map<int, int> wr, wc;

int main()
{
    cin >> n >> m >> t;

    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        r.push_back({x, i});
        wr[i] = x;
    }

    for(int i = 1; i <= m; i ++)
    {
        int x;
        cin >> x;
        c.push_back({x, i});
        wc[i] = x;
    }

    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    while (t --)
    {
        int sr, sc, tr, tc;
        cin >> sr >> sc >> tr >> tc;

        int x0 = find(r.begin(), r.end(), make_pair<wr[sr], sr>);

    }
    
    
    return 0;
}