/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// dp[i]为以nums[i]结尾的最大系列的长度
// 边界条件为a[0]=1, 遍历顺序为i:0->nums.size()-1
// if (j < i && nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1) for j in (0, i)
// return max(dp[i]) for i in range(0, nums.size())
// 时间复杂度 O(n**2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;        
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = {0,1,0,3,2,3};
    cout << s.lengthOfLIS(nums) << endl;
}
