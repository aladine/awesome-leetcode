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
  double myPow(double x, int n) {
    if (n < 0) {
      if (n == INT_MIN) return abs(x) == 1.0 ? 1 : 0;
      return 1 / myPow(x, -n);
    }
    if (n == 0) return 1;
    if (n == 1) {
      return x;
    }
    if (x == 1.0) return 1;
    if (n % 2) {
      auto c = myPow(x, (n - 1) / 2);
      return x * c * c;
    }
    double c = myPow(x, n / 2);
    return c * c;
    /*
     if (n == std::numeric_limits<int>::lowest()) {
            return myPow(1 / x, -(n + 1)) / x;
        }
        if (n < 0) {
            return myPow(1 / x, -n);
        }
        double ans = 1;
                while (n) {
                        if (n & 1 == 1) ans *= x;
                        x *= x;
                        n >>= 1;
                }
                return ans;*/
  }

  // https://leetcode.com/problems/is-graph-bipartite/
  bool colorHelper(vector<vector<int>> g, vector<int>& colors, int v,
                   int color) {
    if (colors[v] != -1 && colors[v] != color) return false;
    colors[v] = color;
    for (auto n : g[v]) {
      if (!colorHelper(g, colors, n, 1 - color)) return false;
    }

    return true;
  }

  bool isBipartite(vector<vector<int>>& graph) {
    const int N = graph.size();
    vector<int> colors(N, -1);
    for (int i = 0; i < N; ++i) {
      if (colors[i] == -1) {
        if (!colorHelper(graph, colors, i, 0)) return false;
      }
    }
    return true;
  }

  // https://leetcode.com/problems/custom-sort-string/
  string customSortString(string S, string T) {
    int count[26] = {0};
    int i = 0;
    for (auto& c : S) {
      count[c - 'a'] = i++;
    }

    auto cmp = [&count](const char& a, const char& b) {
      return count[a - 'a'] < count[b - 'a'];
    };
    std::sort(std::begin(T), std::end(T), cmp);
    return T;
  }

  // https://leetcode.com/problems/task-scheduler/
  int leastInterval(vector<char>& tasks, int n) {
    int ans = 0;
    const int T = tasks.size();
    if (n == 0) {
      return T;
    }

    int count[26] = {0};
    for (auto& c : tasks) {
      count[c - 'A']++;
    }

    vector<ii> sch;
    for (int i = 0; i < 26; ++i) {
      if (count[i]) sch.emplace_back(count[i], i);
    }

    std::sort(std::begin(sch), std::end(sch), std::greater<ii>());
    int lastSize = 0;
    while (!sch.empty()) {
      lastSize = sch.size();
      for (auto& s : sch) {
        s.second--;
      }
      ans += max(n, lastSize);
      for (int i = lastSize - 1; i >= 0; --i) {
        if (sch[i].second == 0) {
          sch.pop_back();
        } else
          break;
      }
    }
    return ans - lastSize;
  }
  // very hard greedy problem
  // int ans = (count-1)*(n+1);
  //  for(auto e : mp) if(e.second == count) ans++;
  //  return max((int)tasks.size(), ans);

  // https://leetcode.com/problems/kth-smallest-element-in-a-bst/
  int kthSmallest(TreeNode* root, int k) {
    if (root == nullptr) return 0;

    int v = getTreeSize(root->left);
    if (v >= k) {
      return kthSmallest(root->left, k);
    }
    if (v + 1 == k) {
      return root->val;
    }

    return kthSmallest(root->right, k - v - 1);
  }
  // Other solutions:
  // - using stack for inorder traversal
  // - using recursion for inorder travesal
  // - using binary search like above.
  // Follow up:
  // - If tree has frequent insert/delete, then we could cache the getTreeSize

  int getTreeSize(TreeNode* r) {
    if (r == NULL) {
      return 0;
    }
    return 1 + getTreeSize(r->left) + getTreeSize(r->right);
  }

  // https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
     string minRemoveToMakeValid(string s) {
       string ans;
       return ans;
    }
};

int main(int argc, char* argv[]) {
  // Solution s = Solution();
  return 0;
}
