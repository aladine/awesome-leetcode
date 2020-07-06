/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (59.62%)
 * Likes:    853
 * Dislikes: 60
 * Total Accepted:    99.1K
 * Total Submissions: 162.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 *
 * Input:
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \
 * ⁠     5   3   9
 *
 * Output: [1, 3, 9]
 *
 *
 *
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()
class Solution {
 public:
  void dfsTree(TreeNode* r, int level, vi& ans) {
    if (r == nullptr) return;
    if (ans.size() < level + 1)
      ans.push_back(r->val);
    else {
      ans[level] = max(ans[level], r->val);
    }
    dfsTree(r->left, level + 1, ans);
    dfsTree(r->right, level + 1, ans);
  }
  vector<int> largestValues(TreeNode* root) {
    vi ans;
    dfsTree(root, 0, ans);
    return ans;
  }
};
// @lc code=end
