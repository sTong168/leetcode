/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start

/*
对于一个凸多边形，定义其顶点的编号为 0 到 n-1，按顺时针方向排列。给定一个整数数组 values，其中 values[i] 是第 i 个顶点的值。
令socres[polygon]表示由顶点 i, j, k 围成的多边形 polygon={i, j, k}（可能有大于三个顶点）的分数
scores[polygon] = min{sum{triangle}}
scores[triangle] = values(i)*values(j)*values(k)
*/
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    // 输入values与两个序号，返回二者之间所夹的多边形的值向量
    inline vector<int> retPoly(vector<int>& values, int m, int n) {
        vector<int> poly;
        if (n > m) {
            for (int k = m; k <= n; ++k) {
                poly.push_back(values[k]);
            }
        } else if (n < m) {
            for (int k = 0; k <= m; ++k) {
                poly.push_back(values[k]);
            }
            for (int k = n; k < values.size(); ++k) {
                poly.push_back(values[k]);
            }
        }
        return poly;
    }

    int minScoreTriangulation(vector<int>& values) {
        unordered_map<vector<int>, int> scores;
        vector<int> curTri{0, 1, 2};
        vector<int> curPoly;
        int ret = 0;
        if (values.size() < 3) {
            return 0;
        } else if(values.size() == 3) {
            return values[0] * values[1] * values[2];
        } else {
            for (auto i = values.begin() + 1; i != values.end(); ++i) {
                if (i - values.begin() > 1) {
                    curPoly = retPoly(values, 0, i - values.begin());
                    ret += minScoreTriangulation(curPoly);
                }
                for (auto j = i + 1; j != values.end(); ++j) {                
                    curTri[1] = i - values.begin();
                    curTri[2] = j - values.begin();
                    curPoly = retPoly(values, i - values.begin(), j - values.begin());
                    ret += minScoreTriangulation(curPoly);
                    curPoly = retPoly(values, j - values.begin(), 0);
                    ret += minScoreTriangulation(curPoly);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> values = {1,2,3};
    cout << s.minScoreTriangulation(values) << endl;
    return 0;
}
