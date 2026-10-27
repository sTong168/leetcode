/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.size() == 0) {
            return 0;
        } else if (stones.size() == 1) {
            return stones[0];
        }
        vector<int> dp(stones.size(), 0);
        dp[0] = stones[0];
        for (int i = 1; i < stones.size(); ++i) {
            dp[i] = min(dp[i-1], )
        }
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> stones = {1,5,11,5};
    cout << s.lastStoneWeightII(stones) << endl;
}
