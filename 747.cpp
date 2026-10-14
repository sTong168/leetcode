/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        uint8_t i;
        uint8_t m1, m2;
        if (nums.size() <= 1)
            return -1;
        for(i = 0; i < nums.size(); ++i) {
            if (i <= 1){
                if (nums.at(0) >= nums.at(1)) {
                    m1 = 0;
                    m2 = 1;
                } else {
                    m1 = 1;
                    m2 = 0;
                }   
            } else {
                if (nums.at(i) > nums.at(m1)) {
                    m2 = m1;
                    m1 = i;
                } else if (nums.at(i) > nums.at(m2)) {
                    m2 = i;
                }
            }
        }
        if(nums.at(m1) >= 2 * nums.at(m2))
            return m1;
        else
            return -1;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> nums = {3,6,1,0};
    cout << s.dominantIndex(nums);
    return 0;
}
