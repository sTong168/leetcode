/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start

/*
对于一个凸多边形，定义其顶点的编号为 0 到 n-1，按顺时针方向排列。给定一个整数数组 values，其中 values[i] 是第 i 个顶点的值。
令socres[polygon]表示由顶点 i, j, k 围成的多边形 polygon={i, j, k}（可能有大于三个顶点）的分数
scores[polygon] = min{sum{triangle}}
scores[triangle] = values(i)*values(j)*values(k)
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    // 输入values与两个序号，返回二者之间所夹的多边形的值向量
    // inline vector<int> retPoly(vector<int>& values, int m, int n) {
    //     vector<int> poly;
    //     if (n > m) {
    //         for (int k = m; k <= n; ++k) {
    //             poly.push_back(values[k]);
    //         }
    //     } else if (n < m) {
    //         for (int k = 0; k <= n; ++k) {
    //             poly.push_back(values[k]);
    //         }
    //         for (int k = m; k < values.size(); ++k) {
    //             poly.push_back(values[k]);
    //         }
    //     }
    //     return poly;
    // }

    int cal_dp(vector<vector<int>>& dp, vector<int>& values, int i, int j) {
        // 输出从 i 到 j 的多边形的 score
        if (dp[i][j] == INT_MAX) {
            if (i <= j) {
                if (j - i <= 1) {
                    dp[i][j] = 0;
                } else if (j - i == 2) {
                    dp[i][j] = values[i] * values[i + 1] * values[j];
                } else {
                    for (int k = i + 1; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] + cal_dp(dp, values, i, k) + cal_dp(dp, values, k, j));
                    }
                }
            } else {
                if (i - j >= values.size() - 1) {
                    dp[i][j] = 0;
                } else if (i - j == values.size() - 2) {
                    dp[i][j] = values[i] * values[(i + 1) % values.size()] * values[j];
                } else {
                    for (int k = 0; k < values.size(); ++k) {
                        if (k == j) k = i + 1;
                        dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] + cal_dp(dp, values, i, k) + cal_dp(dp, values, k, j));
                    }
                }
                // dp[i][j] = cal_dp(dp, values, 0, j) + cal_dp(dp, values, i, values.size()-1);

            }
        }
        return dp[i][j];
    }

    int minScoreTriangulation(vector<int>& values) {
        // static map<vector<int>, int> scores;
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), INT_MAX));
        // vector<int> curPoly, curTri;
        int best(INT_MAX), ret;
        int i, j;
        for (i = 1; i < values.size() - 1; ++i) {
            for (j = i + 1; j < values.size(); ++j) {
                ret = values[0] * values[i] * values[j];
                ret += cal_dp(dp, values, 0, i);
                ret += cal_dp(dp, values, i, j);
                ret += cal_dp(dp, values, j, 0);
                best = min(best, ret);

                // best = min(best, values[0] * values[i] * values[j] + cal_dp(dp, values, 0, i) + cal_dp(dp, values, i, j) + cal_dp(dp, values, j, 0));
            }
        }
        return best;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> values = {2,3,4,5,6};
    // vector<int> new_values = s.retPoly(values, 3, 1);
    // for (int i: new_values) {
    //     cout << i << ' ';
    // }
    // cout << s.minScoreTriangulation(values) << endl;
    vector<vector<int>> dp(values.size(), vector<int>(values.size(), INT_MAX));
    cout << s.cal_dp(dp, values, 2, 0) << endl;
    return 0;
}
