/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (53.15%)
 * Likes:    1516
 * Dislikes: 46
 * Total Accepted:    67.9K
 * Total Submissions: 125.1K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * Your are given an array of integers prices, for which the i-th element is
 * the price of a given stock on day i; and a non-negative integer fee
 * representing a transaction fee.
 * You may complete as many transactions as you like, but you need to pay the
 * transaction fee for each transaction.  You may not buy more than 1 share of
 * a stock at a time (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 *
 * Example 1:
 *
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] =
 * 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) =
 * 8.
 *
 *
 *
 * Note:
 * 0 < prices.length .
 * 0 < prices[i] < 50000.
 * 0 .
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int ll;

#define len(container) int((container).size())
#define all(c) (c).begin(), (c).end()

template <int group = 20, typename ITER>
void show(const char* note, ITER begin, ITER end) {
  cout << note;
  for (int i = 1; begin != end; i++) {
    std::cout << *(begin++) << ' ';
    if (i % group == 0 or begin == end) cout << endl;
  }
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
public:
 int maxProfit(vector<int>& prices, int fee) {
   const int N = prices.size();
   int k = N / 2;
   vector<vi> dp(k + 1, vector<int>(N, 0));
   int res = 0;

   // sell at position i
   for (int i = 1; i <= k; i++) {
     for (int j = 1; j < N; j++) {
       dp[i][j] = dp[i - 1][j];
       int msf = 0;
       for (int l = 0; l < j; ++l) {
         if (l) msf = max(msf, dp[i - 1][l - 1]);
         if (prices[l] <= prices[j]) {
           dp[i][j] = max(dp[i][j], msf + prices[j] - prices[l] - fee);
         }
       }
       res = max(res, dp[i][j]);
     }
   }

   return res;
 }
};
// @lc code=end

