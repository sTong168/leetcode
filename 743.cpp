/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
        for (auto e: times) {
            g[e[0]-1][e[1]-1] = e[2];
        }
        
        vector<int> dist2k(n, INT_MAX);
        dist2k[k - 1] = 0;

        // =========BFS=========
        // vector<bool> visited(n, 0);
        // deque<int> stack;
        // stack.push_back(k - 1); 

        // while (!stack.empty()) {
        //     int u = stack.front();
        //     stack.pop_front();
        //     visited[u] = 1;
        //     for (int v = 0; v < n; ++v) {
        //         if (g[u][v] != INT_MAX){
        //             if (!visited[v]){
        //                 stack.push_back(v);
        //             }
        //             if (dist2k[v] > dist2k[u] + g[u][v]) {
        //                 dist2k[v] = dist2k[u] + g[u][v];
        //                 stack.push_back(v);
        //             }
        //         }
        //     }
        // }
        // =========Dijkstra=======
        vector<bool> unmap(n, 1);
        bool tn(1); // tn==0: map all
        for (int it = 0; it < n; ++it) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (unmap[i]) {
                    if (u == -1 || dist2k[u] > dist2k[i]) {
                        u = i;
                    }
                }
                
            } // min u

            if (u == -1 || dist2k[u] == INT_MAX)
                break;

            unmap[u] = 0;
            for (int i = 0; i < n; ++i) {
                if (unmap[i] && g[u][i] != INT_MAX) {
                    dist2k[i] = min(dist2k[i], dist2k[u] + g[u][i]);
                }
            }
        }

        int max_t = -1;
        for (int i = 0; i < n; ++i) {
            if (dist2k[i] != 0)
                max_t = max(max_t, dist2k[i]);
        }

        // DEBUG
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << ((g[i][j]==INT_MAX)?0:g[i][j]) << '\t';
        //     }
        //     cout << "dist2k = " << dist2k[i] << endl;
        // }

        return (max_t==INT_MAX)?-1:max_t;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<vector<int>> times = {{2,3,1},{3,4,1},{2,1,1}};
    int n = 4;
    int k = 2;
    cout << s.networkDelayTime(times, n, k) << endl;
    return 0;
}
