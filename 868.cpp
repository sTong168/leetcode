/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        bool t = 0;
        unsigned char i;
        unsigned char j = 0, k = 0;
        unsigned char max = 0;
        for(i = 0; (n >> i)&&(i < 32); i++){
            if((n>>i)&1){
                if(t == 0){
                    j = i;
                    t = 1;
                } else {
                    k = j;
                    j = i;
                    if(j - k > max){
                        max = j - k;
                    }
                }
            } 
        }
        return max;
    }
};
// @lc code=end
int main(){
    Solution s;
    cout << s.binaryGap(22);
    return 0;
}
