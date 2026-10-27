/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition2(vector<int>& nums) {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        if (sum_val % 2)
            return 0;
        else {
            sum_val /= 2;
            vector<vector<bool>> dp(nums.size(), vector<bool>(sum_val + 1, 0));
            dp[0][nums[0]] = 1; // dp[0] initial
            for (int i = 1; i < nums.size(); ++i) {
                for (int j = 0; j <= sum_val; ++j) {
                    if (j - nums[i] < 0) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                    }
                }
            }
            // for (int i = 0; i < dp.size(); ++i) {
            //     for (int j = 0; j < dp[0].size(); ++j) {
            //         cout << dp[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            return dp[nums.size()-1][sum_val];
        }
    }

    bool canPartition(vector<int>& nums) {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        if (sum_val % 2)
            return 0;
        else {
            sum_val /= 2;
            vector<bool> dp(sum_val + 1, 0);
            dp[0] = 1; // dp[0] initial
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = sum_val; j >= nums[i]; --j) {
                    dp[j] = dp[j] | dp[j-nums[i]];
                }
            }
            // for (int j = 0; j < dp.size(); ++j) {
            //         cout << dp[j] << ' ';
            // }
            return dp[sum_val];
        }
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout << s.canPartition(nums) << endl;
}
