#include <iostream>
#include <vector>
using namespace std;

const int N = 3e6 + 10;
int n, res;
vector<int> a;
vector<int> b;

int check(int x)
{
    for(int i = 2; i * i < x; i ++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    return 0;
}