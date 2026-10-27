/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays2(vector<int>& nums, int target) {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum_val + 1, 0)); // -n~-1 0 1~n
        if (abs(target) > sum_val)
            return 0;
        int offset = sum_val;
        dp[0][offset+sum_val] = 1;
        dp[0][offset+sum_val-2*nums[0]] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = -sum_val; j <= sum_val; ++j) {
                dp[i][offset+j] = dp[i-1][offset+j];
                if (offset+j+2*nums[i] < 2*sum_val+1)
                    dp[i][offset+j] += dp[i-1][offset+j+2*nums[i]];
            }
        }

        // for (int i = 0; i < dp.size(); ++i) {
        //     for (int j = -sum_val; j <= sum_val; ++j) {
        //         cout << dp[i][offset+j] << '\t';
        //     }
        //     cout << '\n';
        // }

        return dp[nums.size() - 1][offset+target];
    }

        int findTargetSumWays(vector<int>& nums, int target) {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * sum_val + 1, 0); // -n~-1 0 1~n
        if (abs(target) > sum_val)
            return 0;
        int offset = sum_val;
        dp[offset+sum_val] = 1;
        dp[offset+sum_val-2*nums[0]] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = -sum_val; j <= sum_val; ++j) {
                dp[offset+j] = dp[offset+j];
                if (offset+j+2*nums[i] < 2*sum_val+1)
                    dp[offset+j] += dp[offset+j+2*nums[i]];
            }
        }

        // for (int i = 0; i < dp.size(); ++i) {
        //     for (int j = -sum_val; j <= sum_val; ++j) {
        //         cout << dp[i][offset+j] << '\t';
        //     }
        //     cout << '\n';
        // }

        return dp[offset+target];
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = {1,1,1,1};
    int target = 2;
    cout << s.findTargetSumWays(nums, target) << endl;
}
