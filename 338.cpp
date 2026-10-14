/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countBit(int n){
        int i;
        int ans = 0;
        // 我的求法
        // for (i = 0; (n>>i)>0; i++){ //共 i 位
        //     ans += (n>>i)&1;
        // }
        
        // Brian Kernighan 算法
        for (ans = 0; n > 0; ans++){
            n &= n-1;
        }
        
        return ans;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        int i;
        for (i = 0; i <= n; i++){
            ans.push_back(countBit(i));
        }
        return ans;
    }
};
// @lc code=end
int main(void){
    int a = 5;
    Solution s;
    vector<int> ret = s.countBits(a);
    for (int b: ret){
        cout << b << ' ';
    }
    return 0;
}
