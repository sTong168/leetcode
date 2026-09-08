/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int h, w;
        h = matrix.size();
        if (h != 0)
            w = matrix.at(0).size();
        vector<vector<int>> matrix_t(w, vector<int>(h, 0));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                matrix_t.at(j).at(i) = matrix.at(i).at(j);
            }
        }
        return matrix_t;
    }
};
// @lc code=end
int main(void){
    Solution s;
    vector<vector<int>> matrix(2, vector<int>(3, 0));
    vector<vector<int>> matrix_t(3, vector<int>(2, 0));
    matrix[0] = {1, 2, 3};
    matrix[1] = {4, 5, 6};
    matrix_t = s.transpose(matrix);
    
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 2; ++j){
            cout << matrix_t[i][j] << ' ';
        }
        cout << '\n';
    }
}
