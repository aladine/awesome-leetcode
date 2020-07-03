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

// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vi> res;
    if (root == nullptr) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      const int l = q.size();
      vi tmp;
      for (int i = 0; i < l; i++) {
        auto p = q.front();
        q.pop();
        tmp.push_back(p->val);
        if (p->left != nullptr) q.push(p->left);
        if (p->right != nullptr) q.push(p->right);
      }
      res.push_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char* argv[]) {
  // Solution s = Solution();
  return 0;
}
