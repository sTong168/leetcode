/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// TreeNode* buildTree(vector<string>& a) {
//     if (a.empty() || a[0] == "null") return nullptr;

//     TreeNode* root = new TreeNode(stoi(a[0]));
//     queue<TreeNode*> q;
//     q.push(root);

//     int i = 1;
//     while (!q.empty() && i < (int)a.size()) {
//         TreeNode* cur = q.front();
//         q.pop();
//         if (i < (int)a.size() && a[i] != "null") {
//             cur->left = new TreeNode(stoi(a[i]));
//             q.push(cur->left);
//         }
//         i++;
//         if (i < (int)a.size() && a[i] != "null") {
//             cur->right = new TreeNode(stoi(a[i]));
//             q.push(cur->right);
//         }
//         i++;
//     }
//     return root;
// }

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // TreeNode *it;
        int ret;
        if (root == nullptr) {
            ret = 0;
        } else if (root->val <= low) {
            ret = rangeSumBST(root->right, low, high);
            if (root->val == low)
                ret += root->val;
        } else if (root->val >= high) {
            ret = rangeSumBST(root->left, low, high);
            if (root->val == high)
                ret += root->val;
        } else {
            ret = root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        }
        return ret;
    }
};
// @lc code=end
int main() {
    Solution s;

    TreeNode* root = new TreeNode(10);
    vector<string> strRoot = {"15","9","21","7","13","19","23","5","null","11","null","17"};
    // vector<string> strRoot = {"10","5","15","3","7","null","18"};
    // vector<string> strRoot = {"2","1","3"};
    root = buildTree(strRoot);
    cout << s.rangeSumBST(root, 5, 11) << endl;
}
