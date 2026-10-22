/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), 0));
        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i-1][j-1] + 1;
                } else 
                    dp[i][j] = (i == 0 && j == 0) ? 0 :
                                (i == 0 && j != 0) ? dp[i][j-1] : 
                                (i != 0 && j == 0) ? dp[i-1][j] : max(dp[i][j-1], dp[i-1][j]);
                }
            }
        return dp[text1.size()-1][text2.size()-1];
    }
};
// @lc code=end
int main () {
    string text1 = "abcde";
    string text2 = "ace";
    Solution s;
    cout << s.longestCommonSubsequence(text1, text2) << endl;
}
