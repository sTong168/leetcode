/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int lastStoneWeightII2(vector<int>& stones) {
        if (stones.size() == 0) {
            return 0;
        } else if (stones.size() == 1) {
            return stones[0];
        }
        int sum_val = accumulate(stones.begin(), stones.end(), 0);
        int target = sum_val / 2;
        vector<vector<bool>> dp(stones.size(), vector<bool>(sum_val+1, 0));
        dp[0][0] = 1;
        dp[0][stones[0]] = 1;
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 0; j <= sum_val; ++j) {
                if (dp[i-1][j] || (j-stones[i]>=0 && dp[i-1][j-stones[i]])) {
                    dp[i][j] = 1;
                }
            }
        }
        // for (int i = 0; i < stones.size(); ++i) {
        //     for (int j = 0; j <= sum_val; ++j) {
        //         cout << dp[i][j] << '\t';
        //     }
        //     cout << endl;
        // }
        for (int j = target; j >= 0; --j) {
            if (dp[stones.size()-1].at(j)) {
                return sum_val - 2 * j;
            }
        }
        return 0;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        int max_v = 0;
        vector<bool> dp(s + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = s; j >= stones[i]; --j) {
                if (j == stones[i] || (j > stones[i] && dp[j - stones[i]])) {
                    dp[j] = 1;
                    max_v = (j <= s / 2) ? max(max_v, j) : max_v;
                } 
            }
        }
        return s - 2 * max_v;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> stones = {31,26,33,21,40};
    cout << s.lastStoneWeightII(stones) << endl;
}
