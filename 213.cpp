/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpl(n-1, 0);
        vector<int> dpr(n-1, 0);
        if (n == 1) {
            return nums[0];
        }
        if (n >= 2) {
            dpl[0] = nums[0];
            dpr[0] = nums[1];
        }
        if (n >= 3) {
            dpl[1] = max(nums[0], nums[1]);
            dpr[1] = max(nums[1], nums[2]);
            for (int i = 3; i < n; ++i) {
                dpl[i-1] = max(dpl[i-2], dpl[i-3] + nums[i-1]);
                dpr[i-1] = max(dpr[i-2], dpr[i-3] + nums[i]);
            }
        }   
        return max(dpl[n-2], dpr[n-2]);
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = {1,2,1,1};
    cout << s.rob(nums) << endl;
}
