/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(edges.size(), 0);
        // visited[source] = true;
        vector<int> stk{source};
        int v;
        while (!stk.empty()) {
            v = stk.back();
            stk.pop_back();
            if (!visited[v]) {
                visited[v] = true;
                for (int u: edges[v]) {
                    if (!visited[u])
                        stk.push_back(u);
                }
            }
        }
        return visited[destination];
    }
};
// @lc code=end
int main() {
    Solution s;
    int source = 0;
    int destination = 2;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << s.validPath(edges.size(), edges, source, destination);
    return 0;
}
