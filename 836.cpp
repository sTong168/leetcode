/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] &&
               rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};
// @lc code=end
int main(void){
    Solution s;
    vector rec1 = {0,0,1,1};
    vector rec2 = {1,0,2,1};
    cout << s.isRectangleOverlap(rec1, rec2);
}
