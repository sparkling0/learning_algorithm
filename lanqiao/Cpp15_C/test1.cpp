#include <iostream>
using namespace std;

#define long long
int s = 7385137888721 * 4 + 10470245;

signed main()
{
  // 请在此输入您的代码
  int a = 1e6;
  while(a * a < s)
  {
    a ++;
  }
  cout << a - 1;
  return 0;
}