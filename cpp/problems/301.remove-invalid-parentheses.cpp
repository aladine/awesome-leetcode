/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (41.80%)
 * Likes:    2442
 * Dislikes: 97
 * Total Accepted:    199.5K
 * Total Submissions: 466.9K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 *
 * Example 1:
 *
 *
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 *
 *
 * Example 2:
 *
 *
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 *
 *
 * Example 3:
 *
 *
 * Input: ")("
 * Output: [""]
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
  void helper(string s, int index, int left_removed, int right_removed,
              int pair, string path, unordered_set<string>& result) {
    if (index == s.size()) {
      if (left_removed == 0 && right_removed == 0 && pair == 0)
        result.insert(path);
      return;
    }

    switch (s[index]) {
      case '(': {
        if (left_removed > 0) {
          helper(s, index + 1, left_removed - 1, right_removed, pair, path,
                 result);
        }
        helper(s, index + 1, left_removed, right_removed, pair + 1,
               path + s[index], result);

      } break;
      case ')': {
        if (right_removed > 0) {
          helper(s, index + 1, left_removed, right_removed - 1, pair, path,
                 result);
        }
        if (pair > 0)
          helper(s, index + 1, left_removed, right_removed, pair - 1,
                 path + s[index], result);
      } break;
      default:
        helper(s, index + 1, left_removed, right_removed, pair, path + s[index],
               result);
    }
  }
  vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> result;
    int left_removed = 0;
    int right_removed = 0;
    for (auto c : s) {
      if (c == '(') {
        ++left_removed;
      }
      if (c == ')') {
        if (left_removed != 0) {
          --left_removed;
        } else {
          ++right_removed;
        }
      }
    }
    helper(s, 0, left_removed, right_removed, 0, "", result);
    return vector<string>(result.begin(), result.end());
  }
};
// @lc code=end
