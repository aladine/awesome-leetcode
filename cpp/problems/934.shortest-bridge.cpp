/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (46.12%)
 * Likes:    751
 * Dislikes: 60
 * Total Accepted:    27.4K
 * Total Submissions: 57.5K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.)
 *
 * Now, we may change 0s to 1s so as to connect the two islands together to
 * form 1 island.
 *
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed
 * that the answer is at least 1.)
 *
 *
 * Example 1:
 * Input: A = [[0,1],[1,0]]
 * Output: 1
 * Example 2:
 * Input: A = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * Example 3:
 * Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 2 <= A.length == A[0].length <= 100
 * A[i][j] == 0 or A[i][j] == 1
 *
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int ll;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()

// @lc code=start
class Solution {
 public:
  const int dirs[5] = {1, 0, -1, 0, 1};
  void updateQueue(vector<vector<int>>& A, int i, int j) {
    int N = A.size();
    priority_queue<ii, vector<ii>, std::greater<ii>> q;
    q.emplace(1, i * N + j);

    // add all number of the first island

    // then from each of element of the queue, only expand to 0, and increase
    // the value by 1
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto pp = q.top();
        ii p = {pp.second / N, pp.second % N};
        q.pop();
        if (pp.first == 1)
          A[p.first][p.second] = -1;
        else if (pp.first == 0) {
          A[p.first][p.second] = -2;
        } else
          A[p.first][p.second] = -pp.first;
        for (int j = 0; j < 4; j++) {
          int x = p.first + dirs[i];
          int y = p.second + dirs[i + 1];
          if (x >= 0 && x < N && y >= 0 && y < N && A[x][y] >= 0) {
            q.emplace(A[x][y], x * N + y);
          }
        }
      }
    }
    return;
  }
  int shortestBridge(vector<vector<int>>& A) {
    const int R = A.size();
    if (R == 0) {
      return 0;
    }

    bool found = false;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < R; ++j) {
        if (A[i][j] == 1) {
          found = true;
          updateQueue(A, i, j);
          break;
        }
      }
      if (found) break;
    }

    int ans = 0;

    return ans;
  }
};
// @lc code=end
