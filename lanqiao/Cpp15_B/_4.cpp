#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
string d;
vector<int> A;

void mul(vector<int>& A, int b)
{
    int t = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        t += A[i] * b;
        A[i] = t % 10;
        t /= 10;
    }
    if(t) A.push_back(t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    
    cin >> n;
    cin >> d;
    
    reverse(d.begin(), d.end());
    int idx = d.find('.');
    d.erase(idx, 1);

    for(int i = 0; i < d.size(); i ++) A.push_back(d[i] - '0');

    for(int i = 0; i < n; i ++)
    {
        mul(A, 2);
    }  

    if(A[idx - 1] >= 5) 
    {
        int t = 1;
        for(int i = idx; i < A.size(); i ++)
        {
            t += A[i];
            A[i] = t % 10;
            t /= 10;
        }
        if(t) A.push_back(t);
    }

    for(int i = A.size() - 1; i >= idx; i --) cout << A[i];

    return 0;
}