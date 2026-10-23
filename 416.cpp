/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(1, nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < dp.size(); ++j) {
                if (dp[j] == nums[i]) {
                    return 1;
                } else {
                    dp.push_back(nums[i]);
                    dp.push_back(dp[j] + nums[i]);
                    dp.push_back(dp[j] - nums[i]);
                }
            }
        }
        return 0;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = {1,2,3,5};
    cout << s.canPartition(nums) << endl;
}
