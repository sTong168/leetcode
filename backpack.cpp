// 背包问题描述 (0-1 背包)
// 有一个背包，最大承重为 m（可以理解为有 m 个格子，每个物品占用若干格子）。
// 现在有 n 个物品，每个物品有一个重量 w[i] 与价值 v[i]。
// 目标是在满足重量限制的前提下，让背包中物品的总价值最大。
/*

dp[i][j]: 前(i+1)个物品、容量为 j 时的最大价值

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxValue(int m, int n, vector<int>& w, vector<int>& v) {
    // 行 = 物品个数 n，列 = 容量 0..m
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j < w[i]) {
                dp[i][j] = (i >= 1) ? dp[i-1][j] : 0;
            } else {
                int take = (i >= 1) ? dp[i-1][j - w[i]] + v[i] : v[i];
                int notTake = (i >= 1) ? dp[i-1][j] : 0;
                dp[i][j] = max(take, notTake);
            }
        }
    }
    return dp[n-1][m];
}

int main() {
    int m = 8;
    int n = 5;
    vector<int> w = {1,2,1,3,4};
    vector<int> v = {3,2,1,4,2};
    cout << maxValue(m, n, w, v) << endl;
    return 0;
}
