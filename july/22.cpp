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
  // https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
  string removeDuplicates(string s, int k) {
    string st;
    const int N = s.length();
    for (int i = 0; i < N; ++i) {
      char c = s[i];
      if (!st.empty() && c == st.back() && st.size() >= k - 1) {
        bool isValid =
            all_of(st.end() - k + 1, st.end(), [&](char j) { return j == c; });
        if (isValid) {
          st.resize(st.size() - k + 1);
          continue;
        }
      }
      st.push_back(c);
    }
    return st;
  }
  // OR using a stack of pair<int, char>

  // https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    bool isReverse = false;
    while (!q.empty()) {
      vector<int> row;
      for (int i = q.size(); i > 0; --i) {
        auto p = q.front();
        q.pop();
        row.push_back(p->val);
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
      }
      if (isReverse) {
        reverse(row.begin(), row.end());
      }
      isReverse = !isReverse;
      res.push_back(row);
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution s = Solution();
  cout << s.removeDuplicates("deeedbbcccbdaa", 3);
  return 0;
}
