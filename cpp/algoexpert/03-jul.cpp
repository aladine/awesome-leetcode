#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()

template <typename ITER>
void show(ITER begin, ITER end) {
  for (int i = 1; begin != end; i++) {
    printf("%d ", *(begin++));
    if (i % 20 == 0 or begin == end) printf("\n");
  }
};

inline bool isValid(int x, int y, int R, int C) {
  return x >= 0 && x < R && y >= 0 && y < C;
}

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxSubsetSumNoAdjacent(vector<int> array) {
  const int N = array.size();
  if (N == 0) {
    return 0;
  }
  if (N == 1) {
    return array[0];
  }

  int tmp;
  int prev = 0, curr = array[0];

  for (int i = 1; i < N; ++i) {
    tmp = prev;
    prev = curr;
    curr = max(tmp + array[i], curr);
  }

  return curr;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  if (n == 0) {
    return 1;
  }
  const int D = denoms.size();
  vector<int> ways(n + 1, 0);
  ways[0] = 1;
  for (int i = 0; i < D; ++i) {
    int d = denoms[i];
    for (int j = n; j >= 0; --j) {
      int k = j / d;
      for (int l = 1; l <= k; ++l) {
        ways[j] += ways[j - l * d];
      }
    }
  }
  return ways[n];
}
// Instead of iterating in reverse way, we can just iterate normal way with
// adding the denom value. Time: O(nd) | Space: O(n)

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> ways(n + 1, INT_MAX);
  ways[0] = 0;
  for (auto& denom : denoms) {
    for (int i = denom; i < n + 1; ++i) {
      if (ways[i - denom] != INT_MAX)
        ways[i] = min(ways[i], ways[i - denom] + 1);
    }
  }
  return ways[n] == INT_MAX ? -1 : ways[n];
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  const int N = array.size();
  vector<int> parents(N, -1);
  vector<int> lis(N, 0);  // lis = array
  lis[0] = array[0];
  for (int i = 1; i < N; ++i) {
    lis[i] = array[i];
    for (int j = 0; j < i; ++j) {
      if (array[j] < array[i] && lis[i] < lis[j] + array[i]) {
        lis[i] = lis[j] + array[i];
        parents[i] = j;
      }
    }
  }

  auto it = max_element(all(lis));
  int st = it - lis.begin();
  vi ans;

  while (st >= 0) {
    ans.push_back(array[st]);
    st = parents[st];
  }

  reverse(all(ans));

  return {
      {*it},  // Sum of sequence.
      ans,    // Elements of the sequence.
  };
}

vector<char> longestCommonSubsequence(string str1, string str2) {
  int l1 = str1.length(), l2 = str2.length();
  vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
  int im = 0, jm = 0;
  for (int i = 1; i <= l1; ++i) {
    for (int j = 1; j <= l2; ++j) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      if (dp[i][j] > dp[im][jm]) {
        im = i;
        jm = j;
      }
    }
  }

  if (im == 0 && jm == 0) {
    return {};
  }

  vector<char> ans;
  while (im >= 1 && jm >= 1) {  // OR im != 0 && jm != 0
    if (str1[im - 1] == str2[jm - 1]) {
      ans.push_back(str1[im - 1]);
      im--;
      jm--;
    } else if (dp[im][jm] == dp[im][jm - 1]) {
      jm--;
    } else
      im--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
// Time: O(nm) | Space: O(nm)

int minNumberOfJumps(vector<int> array) {
  const int N = array.size();
  vector<int> jumps(N, INT_MAX);
  jumps[0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j <= min(N - 1, i + array[i]); ++j) {
      jumps[j] = min(jumps[j], 1 + jumps[i]);
    }
  }
  return jumps[N - 1];
}
// Time: O(n^2) | Space: O(n)
// Advance solution: O(n) using maxReach.
// maxReach = array[0]
// i = 1-> end: maxReach = max(maxReach, i + array[i])
// step--
// if (step==0) jump++; steps = maxReach - i

// https://www.algoexpert.io/questions/Square%20of%20Zeroes
// Time: O(n^3) | Space: O(n^2)
bool squareOfZeroes(vector<vector<int>> matrix) {
  const int N = matrix.size();
  vector<vector<int>> upper(N, vector<int>(N, 0));
  vector<vector<int>> down(N, vector<int>(N, 0));
  vector<vector<int>> left(N, vector<int>(N, 0));
  vector<vector<int>> right(N, vector<int>(N, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      if (matrix[i][j] == 0) {
        left[i][j] = 1 + left[i][j - 1];
      }
    }

    for (int j = N - 2; j >= 0; --j) {
      if (matrix[i][j] == 0) {
        right[i][j] = 1 + right[i][j + 1];
      }
    }
  }

  for (int j = 0; j < N; ++j) {
    for (int i = 1; i < N; ++i) {
      if (matrix[i][j] == 0) {
        up[i][j] = 1 + up[i][j - 1];
      }
    }

    for (int i = N - 2; i >= 0; ++i) {
      if (matrix[i][j] == 0) {
        down[i][j] = 1 + down[i][j + 1];
      }
    }
  }
  // calc by check for each coordinate
  // the number of up and left, then check the down and right on the diagonal.
  return false;
}

int kadanesAlgorithm(vector<int> array) {
  int curr = 0;
  int maxSoFar = INT_MIN;
  for (int i = 0; i < array.size(); ++i) {
    curr = max(array[i], array[i] + curr);
    maxSoFar = max(maxSoFar, curr);
  }
  return maxSoFar;
}

// https://www.algoexpert.io/questions/Topological%20Sort
unordered_map<int, vi> adjList;
unordered_map<int, int> vis;

bool dfs(int j, vi& ans) {
  if (vis[j] == 1) {
    return false;
  } else if (vis[j] == 2) {
    cout << j << endl;
    return true;
  }
  vis[j] = 2;
  for (auto neighbor : adjList[j]) {
    if (dfs(neighbor, ans)) {
      return true;
    }
  }
  vis[j] = 1;
  ans.push_back(j);

  return false;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  vi ans;

  for (auto& dep : deps) {
    adjList[dep[0]].push_back(dep[1]);
  }

  for (auto& job : jobs) {
    if (dfs(job, ans)) {
      return {};
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(int argc, char* argv[]) {
  // [1]
  // 75, 105, 120, 75, 90, 135
  // [1, 2, 3, 4, 5, 6, 7, 8]
  // [[3, 1], [8, 1], [8, 7], [5, 7], [5, 2], [1, 4], [1, 6], [1, 2], [7, 6]]
  vector<int> denoms = {1, 5};
  cout << numberOfWaysToMakeChange(6, denoms);
  return 0;
}
