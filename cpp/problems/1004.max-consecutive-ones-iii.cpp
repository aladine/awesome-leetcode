/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (56.75%)
 * Likes:    1087
 * Dislikes: 22
 * Total Accepted:    55.7K
 * Total Submissions: 94.9K
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 *
 * Return the length of the longest (contiguous) subarray that contains only
 * 1s. 
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * Output: 6
 * Explanation:
 * [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is
 * underlined.
 *
 *
 * Example 2:
 *
 *
 * Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 * Output: 10
 * Explanation:
 * [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is
 * underlined.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 20000
 * 0 <= K <= A.length
 * A[i] is 0 or 1 
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestOnes(vector<int>& A, int K) {
    const int N = A.size();
    if (N <= K) {
      return N;
    }
    int ans = 0;
    int end = -1;
    int zero = 0;
    for (int i = 0; i < N; ++i) {
      if (i != 0 && A[i - 1] == 0) zero--;
      while (end + 1 < N && zero < K) {
        end++;
        zero += A[end] == 1 ? 0 : 1;
      }
      while (end + 1 < N && A[end + 1] == 1) end++;

      if (end >= i) ans = max(ans, end - i + 1);
      if (end == N - 1) break;
    }
    return ans;

    // int i = 0, j;
    // for (j = 0; j < A.size(); ++j) {
    //   if (A[j] == 0) K--;
    //   if (K < 0 && A[i++] == 0) K++;
    // }
    // return j - i;
  }
};
// @lc code=end
