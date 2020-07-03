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
  void dfsDecoding(string s, int st, int cur, int &res) {
    if (st == s.length()) {
      // cout << cur << endl;
      res += cur;
      return;
    }

    switch (s[st]) {
      case '*': {  //
      } break;
      case '1': {  //
      } break;
      case '2': {  //
      } break;
        if (st + 1 < s.length()) {
          cur += s[st];
          dfsDecoding(s, st + 1, cur, res);
          if (s[st + 1] < '7')
            dfsDecoding(s, st + 2, cur, res);
          else if (s[st + 1] == '*') {
            dfsDecoding(s, st + 2, 3 * cur, res);
            dfsDecoding(s, st + 2, 6 * cur, res);
          }
        }
      default: {
        cur += s[st];
        dfsDecoding(s, st + 1, cur, res);
      } break;
    }
  }

  int numDecodings(string s) {
    const int N = s.length();
    int res = 0;
    dfsDecoding(s, 0, "", res);
    return res;
  }
};
// @lc code=end
