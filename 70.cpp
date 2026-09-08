/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        static int ans[100];
        if (ans[n]) return ans[n];
        else if (n <= 2) ans[n] = n;
        else ans[n] = climbStairs(n-1)+climbStairs(n-2);
        return ans[n];
    }
};
// @lc code=end

