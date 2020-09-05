/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (56.37%)
 * Likes:    3778
 * Dislikes: 123
 * Total Accepted:    836.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * Example:
 *
 *
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Note:
 *
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    const int N = nums.size();
    if (N == 0) {
      return;
    }
    int i = 0;
    for (int j = 0; j < N; j++) {
      if (nums[j] != 0) {
        nums[i++] = nums[j];
      }
    }

    while (i < N) nums[i++] = 0;
  }
};
// @lc code=end
