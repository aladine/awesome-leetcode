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
     int nthUglyNumber(int n) {

   if (n==1) {
     return 1;
   }
     vector<int> nums(n);
        int l2 =0, l3 = 0, l5 = 0;
     nums[0] = 1;
     for (int i = 1; i < n; ++i) {
         while(2*nums[l2] <= nums[i-1] )l2++;
         while(3*nums[l3] <= nums[i-1] )l3++;
         while(5*nums[l5] <= nums[i-1] )l5++;
       nums[i] = min({5*nums[l5], 3*nums[l3], 2*nums[l2]});
         if(nums[i] == 2*nums[l2]) l2++;
         else  if(nums[i] == 3*nums[l3]) l3++;
         else l5++;
     }
     return nums[n-1];

    }
};

int main(int argc, char* argv[]) {
  // Solution s = Solution();
  return 0;
}
