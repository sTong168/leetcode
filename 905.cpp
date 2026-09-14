/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
#include <cstdint>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        uint16_t loc1 = 0;
        uint16_t loc2 = 0;
        vector<int> new_nums(nums.size());
        for(uint16_t i = 0; i < nums.size(); ++i){
            if (nums.at(i) % 2 == 0){
                new_nums.at(loc1) = nums.at(i);
                ++loc1;
            } else {
                new_nums.at(nums.size()-loc2-1) = nums.at(i);
                ++loc2;
            }
            
        }
        return new_nums;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> nums = {3, 1, 2, 4};
    vector<int> new_nums = s.sortArrayByParity(nums);
    for (uint16_t i = 0; i < nums.size(); ++i){
        cout << nums.at(i) << ' ';
    }
    cout << '\n';
        for (uint16_t i = 0; i < nums.size(); ++i){
        cout << new_nums.at(i) << ' ';
    }
    
    return 0;
}
