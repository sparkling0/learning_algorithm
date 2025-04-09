#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int n, m, k;


int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        cin >> n >> m >> k;
        int t = 1, x = 1;
        while((1 - pow(m,t)) / (1 - m) < n) t ++;
        while((1 - pow(m,x)) / (1 - m) < k) x ++;
        if(x >= t) cout << 1 << endl;
        else 
        {
            
        }
    }
    
    

    return 0;
}