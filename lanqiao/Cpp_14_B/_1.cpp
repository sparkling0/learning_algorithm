#include <iostream>
#include <map>
using namespace std;

const int N = 105;

string a[N];
map<string, int> st;
int res;

int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(string md)
{
    int m = 0, d = 0;
    for(int i = 0; i < 2; i ++)
    {
        m = m * 10 + (md[i] - '0');
    }
    for(int i = 2; i < 4; i ++)
    {
        d = d * 10 + (md[i] - '0');
    }
    if(m >= 1 && m <= 12 && d >= 1 && d <= mon[m - 1]) return true;
    else return false;
}

int main()
{
    for(int i = 0; i < 100; i ++) cin >> a[i];

    for(int i = 0; i < 100; i ++)
    {
        for(int j = i + 1; j < 100; j ++)
        {
            for(int k = j + 1; k < 100; k ++)
            {
                for(int h = k + 1; h < 100; h ++)
                {
                    if(a[i] != "2" || a[j] != "0" || a[k] != "2" || a[h] != "3") continue;
                    for(int x = h + 1; x < 100; x ++)
                    {
                        for(int y = x + 1; y < 100; y ++)
                        {
                            for(int z = y + 1; z < 100; z ++)
                            {
                                for(int w = z + 1; w < 100; w ++)
                                {
                                    string md = a[x] + a[y] + a[z] + a[w];
                                    if(check(md)) 
                                    {
                                        if(st.count(md) == 0) 
                                        {
                                            cout << md << endl;
                                            res ++;
                                        }
                                        st[md] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
}