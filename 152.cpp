/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpMax(nums.size(), INT_MIN);
        vector<int> dpMin(nums.size(), INT_MAX);
        int maxPdx = nums[0];
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dpMax[i] = max(dpMax[i-1]*nums[i], nums[i]);
            dpMax[i] = max(dpMin[i-1]*nums[i], dpMax[i]);
            dpMin[i] = min(dpMax[i-1]*nums[i], nums[i]);
            dpMin[i] = min(dpMin[i-1]*nums[i], dpMin[i]);
            maxPdx = max(maxPdx, dpMax[i]);
        }
        return maxPdx;
    }
};
// @lc code=end
int main () {
    vector<int> nums = {2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}

