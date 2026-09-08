/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t i = 0;
        if (s.empty())
            return true;
        if (s.size() > t.size())
            return false;

        for(char c: t){
            if (i < s.size() && c == s.at(i))
                ++i;
        }
        return (i == s.size());
    }
};
// @lc code=end

int main(void){
    Solution s;
    string a = "";
    string b = "ahbgdc";
    cout << s.isSubsequence(a, b);
}
