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

int maxValue2(int m, int n, vector<int>& w, vector<int>& v) {
    // 二维 dp, 行 = 物品个数 n，列 = 容量 0..m
    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (w[i] <= j) {
                dp[i][j] = (i == 0) ? v[i] : max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            } else {
                dp[i][j] = (i == 0) ? 0 : dp[i-1][j];
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j <= m; ++j) {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }
    return dp[n-1][m];
}

/*
观察 dp[i][j]:
0       3       3       3       3       3       3       3       3
0       3       3       5       5       5       5       5       5
0       3       4       5       6       6       6       6       6
0       3       4       5       7       8       9       10      10
0       3       4       5       7       8       9       10      10
发现dp[i]的大部分数据都继承与dp[i-1] (具体来讲，在 j < w[i]时继承，大于时相当于可以放进新的物品，所以 dp[i] 要更新)
因此可以把 dp[i][j] 改为 dp[j], 只有在 j >= w[i] 时更新 dp[j]
至于遍历顺序，可观察原递推表达式: dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
dp[i][j] 要根据 dp[i-1][j-w[i]] 确定，而若将 j 从小到大遍历，则会导致 dp[i-1][j-w[i]] 被 dp[i][j-w[i]] 覆盖
这样得到的结果不是 0-1 背包而是完全背包问题， 即同一个物品 i 可被拿多次
因此 j 要从大到小遍历
*/

int maxValue1(int m, int n, vector<int>& w, vector<int>& v) {
    // 一维动态数组, 行 = 容量 0..m
    vector<int> dp(m+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            dp[j] = (i == 0) ? v[i] : max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    return dp[m];
}

int main() {
    int m = 8;
    int n = 5;
    vector<int> w = {1,2,1,3,4};
    vector<int> v = {3,2,1,4,2};
    cout << maxValue1(m, n, w, v) << endl;
    return 0;
}
