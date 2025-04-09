#include <iostream>  
#include <vector>  
using namespace std;  
  
const int MAXN = 1000001;  
const long long MOD = 998244353;  
  
int main() {  
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  
    int n;  
    cin >> n;  
    vector<bool> pr(MAXN, true); // 初始化pr数组为0  
    pr[1] = false; // 1不是质数  
  
    // 筛法求质数  
    for (int i = 2; i * i <= MAXN; ++i) {  
        if (pr[i]) {  
            for (int j = i * i; j < MAXN; j += i) {  
                pr[j] = false;  
            }  
        }  
    } 
  
    long long s = 0; // 素数的个数  
    long long t = 0; // 合数的个数  
    long long w = 1; // 非s+1的阶乘模p  
    long long g = 1; // 非2的阶乘模p  
    long long A = 0; // 当前遍历到的素数个数  
    long long B = 0; // 当前遍历到的合数个数  
    long long ans = 0;  
  
    // 统计素数和合数的个数  
    for (int i = 1; i <= n; ++i) {  
        if (pr[i]) {  
            ++s;  
        } else {  
            ++t;  
        }  
    }  
  
    // 计算非s+1的阶乘模p  
    for (int i = 1; i <= n; ++i) {  
        if (i != s + 1) {  
            w = (w * i) % MOD;  
        }  
    }  
  
    // 计算非2的阶乘模p  
    for (int i = 1; i <= n; ++i) {  
        if (i != 2) {  
            g = (g * i) % MOD;  
        }  
    }  
  
    // 计算A，即素数的个数  
    for (int i = 1; i <= n; ++i) {  
        if (pr[i]) {  
            ++A;  
        }  
    }  
  
    //这一行代码计算了由合数组成的所有可能的两两组合的个数（即组合数C(t, 2)）
    //并将其乘以非2的阶乘模p（即g），然后将结果加到ans上。
    //这是为了计算初始时（即没有删除任何素数时）所有合数对组合与g的乘积的和 
    ans = (ans + (t * (t - 1) / 2) % MOD * g) % MOD;  

    // 逆序遍历，更新ans  
    s = 0; // 重置s为0，因为接下来要逆序遍历  
    for (int i = n; i >= 1; --i) {  
        if (pr[i]) {  
            --A; // 素数个数减少  
            ++B; // 合数个数增加  
        } else {  
            // 更新ans  
            ans = (ans + ((A * (A + 1) / 2 + B * (B + 1) / 2) % MOD * w) % MOD) % MOD;  
        }  
    }  
  
    cout << ans << endl;  
    return 0;  
}