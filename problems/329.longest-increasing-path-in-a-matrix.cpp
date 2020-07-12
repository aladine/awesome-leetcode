/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (42.25%)
 * Likes:    1909
 * Dislikes: 36
 * Total Accepted:    146.4K
 * Total Submissions: 339.1K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int dirs[5] = {1, 0, -1, 0, 1};
  int R, C;
  int dfs(vector<vector<int>>& scores, vector<vector<int>>& matrix, int a,
          int b) {
    if (scores[a][b] != -1) {
      return scores[a][b];
    }
    int score = -1;
    for (int i = 0; i < 4; ++i) {
      int x = a + dirs[i];
      int y = b + dirs[i + 1];
      if (x >= 0 && x < R && y >= 0 && y < C) {
        if (matrix[x][y] > matrix[a][b]) {
          score = max(score, 1 + dfs(scores, matrix, x, y));
        }
      }
    }
    scores[a][b] = score;
    return scores[a][b];
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    R = matrix.size();
    if (R == 0) {
      return 0;
    }
    C = matrix[0].size();
    int ans = 0;
    vector<vector<int>> scores(R, vector<int>(C, -1));
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        ans = max(ans, dfs(scores, matrix, i, j));
      }
    }

    return ans;
  }
};
// @lc code=end
