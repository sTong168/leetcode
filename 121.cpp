/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMax(int i, vector<int>& prices){
        int max = prices[i];
        for (int j = i; j < prices.size(); j++){
            if (prices[j] > max)
                max = prices[j];
        }
        return max;
    }

    int maxProfit(vector<int>& prices) {
        int i, j;
        int maxprofit = 0;
        int price_min = prices[0];
        for (i = 0; i < prices.size(); i++){
            if (prices[i] < price_min)
                price_min = prices[i];
            if (prices[i] - price_min > maxprofit)
                maxprofit = (prices[i] - price_min);
        }
        return maxprofit;
    }
};
// @lc code=end

int main(void){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}