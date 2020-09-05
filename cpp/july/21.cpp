#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()

const int M = 1e9 + 7;

template <typename ITER>
void show(ITER begin, ITER end) {
  for (int i = 1; begin != end; i++) {
    printf("%d ", *(begin++));
    if (i % 20 == 0 or begin == end) printf("\n");
  }
};

template <typename T>
void addMod(T& a, T b) {
  a = (a + b) % M;
}

inline bool isValid(int x, int y, int R, int C) {
  return x >= 0 && x < R && y >= 0 && y < C;
}

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int R, C;
  const int dirs[5] = {1, 0, -1, 0, 1};
  bool dfs(vector<vector<char>> b, int i, int j, const string word, int idx,
           vector<vector<int>>& visited) {
    if (word[idx] != b[i][j]) {
      return false;
    }

    if (idx == word.size() - 1) {
      return true;
    }
    visited[i][j] = 1;

    for (int k = 0; k < 4; ++k) {
      int x = i + dirs[k];
      int y = j + dirs[k + 1];
      if (isValid(x, y, R, C) && visited[x][y] == 0) {
        if (dfs(b, x, y, word, idx + 1, visited)) {
          return true;
        }
      }
    }
    visited[i][j] = 0;
    return false;
  }
  // instead of using visited, can use the board  board[i][j] = '*', then change
  // it back
  bool exist(vector<vector<char>>& board, string word) {
    R = board.size();
    if (R == 0) {
      return 0;
    }
    C = board[0].size();

    vector<vector<int>> visited(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        visited.clear();
        if (dfs(board, i, j, word, 0, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  int longestSubarray(vector<int>& nums, int limit) {
    int ans = 0;
    const int N = nums.size();
    for (int i = 0; i < N; ++i) {
      if (i + ans >= N) break;
      int currMin = *min_element(nums.begin() + i, nums.begin() + i + ans);
      int currMax = *max_element(nums.begin() + i, nums.begin() + i + ans);
      int k = i + ans;  // try i to i+ans
      for (; k < N; ++k) {
        currMin = min(currMin, nums[k]);
        currMax = max(currMax, nums[k]);
        if (currMax - currMin > limit)
          break;
        else {
          ans = max(ans, k - i + 1);
        }
      }
    }
    return ans;
  }

  int dfsCompany(int head, vector<vector<int>>& adjList,
                 vector<int>& informTime) {
    int ans = 0;
    for (auto c : adjList[head]) {
      ans = max(ans, dfsCompany(c, adjList, informTime));
    }
    return informTime[head] + ans;
  }

  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; ++i) {
      if (manager[i] != -1) adjList[manager[i]].push_back(i);
    }
    return dfsCompany(headID, adjList, informTime);
  }
};

int main(int argc, char* argv[]) {
  // Solution s = Solution();
  return 0;
}
