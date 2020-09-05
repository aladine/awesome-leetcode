/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (60.27%)
 * Likes:    833
 * Dislikes: 25
 * Total Accepted:    72K
 * Total Submissions: 115.4K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * Given a string s of '(' , ')' and lowercase English characters. 
 *
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in
 * any positions ) so that the resulting parentheses string is valid and return
 * any valid string.
 *
 * Formally, a parentheses string is valid if and only if:
 *
 *
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "(a(b(c)d)"
 * Output: "a(b(c)d)"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is one of  '(' , ')' and lowercase English letters.
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int ll;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()

// @lc code=start
class Solution {
 public:
  void helper(string s, int index, int left, int right, int pair, string path,
              string& result) {
    if (index == s.size()) {
      if (left == 0 && right == 0 && pair == 0) result = path;
      return;
    }

    switch (s[index]) {
      case '(': {
        if (left > 0) {
          helper(s, index + 1, left - 1, right, pair, path, result);
        }
        if (!result.empty()) return;
        helper(s, index + 1, left, right, pair + 1, path + s[index], result);

      } break;
      case ')': {
        if (right > 0) {
          helper(s, index + 1, left, right - 1, pair, path, result);
        }
        if (!result.empty()) return;
        if (pair > 0)
          helper(s, index + 1, left, right, pair - 1, path + s[index], result);
      } break;
      default:
        helper(s, index + 1, left, right, pair, path + s[index], result);
    }
  }

  string minRemoveToMakeValid(string s) {
    int left = 0, right = 0;
    for (char c : s) {
      if (c == '(')
        left++;
      else if (c == ')') {
        if (left > 0)
          left--;
        else
          right++;
      }
    }

    string ans;
    helper(s, 0, left, right, 0, "", ans);
    return ans;
  }
};
// @lc code=end
