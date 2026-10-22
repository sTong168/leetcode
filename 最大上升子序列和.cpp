#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxLISSum(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MIN);
    int max_sum = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; i > j; ++j) {
            if (nums[i] > nums[j]) {
                if (dp[j] + nums[i] > dp[i]) {
                    dp[i] = dp[j] + nums[i];
                }
            }
        }
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum;
}

int main() {
    vector<int> nums = {1,3,4,2,5,3,6,2};
    cout << maxLISSum(nums) << endl;
}