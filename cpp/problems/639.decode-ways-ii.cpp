/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (25.96%)
 * Likes:    395
 * Dislikes: 493
 * Total Accepted:    30.5K
 * Total Submissions: 115.5K
 * Testcase Example:  '"*"'
 *
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 *
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 *
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 *
 *
 *
 *
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 *
 *
 *
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 *
 *
 * Example 1:
 *
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 *
 *
 *
 * Example 2:
 *
 * Input: "1*"
 * Output: 9 + 9 = 18
 *
 *
 *
 * Note:
 *
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 *
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
  const int M = 1e9 + 7;

  void addMod(long &a, long b) { a = (a + b) % M; }
  int numDecodings(string s) {
    const int N = s.length();
    if (N == 0) {
      return 0;
    }
    int res = 0;
    vector<long> nums(N + 1, 0);
    reverse(s.begin(), s.end());
    nums[0] = 1;
    nums[1] = s[0] == '*' ? 9 : (s[0] == '0' ? 0 : 1);
    for (int i = 2; i <= N; ++i) {
      long tmp = nums[i - 1];
      switch (s[i - 1]) {
        case '0':
          tmp = 0;
          break;

        case '*': {
          addMod(tmp, 8 * nums[i - 1]);

          if (s[i - 2] == '*') {
            addMod(tmp, 15 * nums[i - 2]);
          } else if (s[i - 2] < '7') {
            addMod(tmp, 2 * nums[i - 2]);
          } else {
            addMod(tmp, nums[i - 2]);
          }
        } break;

        case '1': {
          addMod(tmp, (s[i - 2] == '*' ? 9 : 1) * nums[i - 2]);
        } break;

        case '2': {
          if (s[i - 2] == '*') {
            addMod(tmp, 6 * nums[i - 2]);
          } else if (s[i - 2] < '7') {
            addMod(tmp, nums[i - 2]);
          }
        } break;

        default:
          break;
      }
      nums[i] = tmp % M;
    }
    return nums[N];
  }
};
// @lc code=end
