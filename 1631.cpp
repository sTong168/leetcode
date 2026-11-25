/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row(heights.size()), col(heights[0].size());
        // vector<vector<int>> g(row * col, vector<int>(row * col, INT_MAX));
        // for (int i = 0; i < row; ++i) {
        //     for (int j = 0; j < col; ++j) {
        //         if (i > 0)
        //             g[i*col+j][(i-1)*col+j] = abs(heights[i][j] - heights[i-1][j]);
        //         if (i < row - 1)
        //             g[i*col+j][(i+1)*col+j] = abs(heights[i][j] - heights[i+1][j]);
        //         if (j > 0)
        //             g[i*col+j][i*col+j-1] = abs(heights[i][j] - heights[i][j-1]);
        //         if (j < col - 1)
        //             g[i*col+j][i*col+j+1] = abs(heights[i][j] - heights[i][j+1]);
        //     }
        // }
        vector<int> dist(row*col, INT_MAX);
        vector<bool> visited(row*col, 0);
        dist[row*col-1] = 0;
        for (int i = 0; i < row*col; ++i) {
            int u = -1;
            for (int j = 0; j < row*col; ++j) {
                if (!visited[j] && (u == -1 || dist[u] > dist[j]))
                    u = j; // min dist node: u
            }    
            if (u == -1 || dist[u] == INT_MAX) { // all visited || min dist = INF
                break;
            }
            visited[u] = 1;
            vector<int> neighbors{};
            if (u%col!=0&&u>=1)
                neighbors.push_back(u-1);
            if (u%col!=col-1&&u<row*col-1)
                neighbors.push_back(u+1);
            if (u/col!=0&&u>=col)
                neighbors.push_back(u-col);
            if (u/col!=col-1&&u<row*col-col)
                neighbors.push_back(u+col);
            for (auto j: neighbors) {
                if (!visited[j])  
                    dist[j] = min(dist[j], max(dist[u], abs(heights[u/col][u%col]-heights[j/col][j%col])));
            }
        }
        // DEBUG
        // for (int i = 0; i < row * col; ++i) {
        //     for (int j = 0; j < row * col; ++j) {
        //         cout << ((g[i][j]==INT_MAX)?0:g[i][j]) << "  ";
        //     }
        //     cout << endl;
        // }
        return dist[0];
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<vector<int>> heights = {{1,10,6,7,9,10,4,9}};
    cout << s.minimumEffortPath(heights) << endl;
    return 0;
}
