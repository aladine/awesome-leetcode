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
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<std::tuple<int, int, int>> res;

    unordered_set<int> s(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
      int d = -nums[i];
      int l = i + 1, h = nums.size() - 1;
      while (l < h) {
        if (nums[l] + nums[h] == d) {
          res.insert({nums[i], nums[l], nums[h]});
          // OR should prune duplicate in this step:
          // while (lo < hi && num[lo] == num[lo+1]) lo++;
          l++;
          h--;
        } else if (nums[l] + nums[h] > d)
          h--;
        else
          l++;
      }
    }

    vector<vector<int>> ans;
    for (auto [k, l, m] : res) {
      ans.push_back({k, l, m});
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  // Solution s = Solution();
  return 0;
}
