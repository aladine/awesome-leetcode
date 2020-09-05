/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (53.48%)
 * Likes:    3773
 * Dislikes: 115
 * Total Accepted:    535.7K
 * Total Submissions: 965.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  void findCombination(vector<vector<int>>& res, const int start,
                       const int target, vector<int>& local,
                       const vector<int>& num) {
    if (target == 0) {
      res.push_back(local);
      return;
    }

    for (int i = start; i < num.size(); i++) {
      if (num[i] > target) return;

      local.push_back(num[i]);
      findCombination(res, i, target - num[i], local, num);
      local.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> local;
    sort(candidates.begin(), candidates.end());
    findCombination(res, 0, target, local, candidates);
    return res;
  }

  int combinationSum4(vector<int>& nums, int target) {
    const int N = nums.size();
    sort(all(nums));
    vector<ll> ways(target + 1, 0);
    ways[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (auto num : nums) {
        if (i < num) break;
        ways[i] = ways[i] + ways[i - num];
      }
    }
    return ways[target];
  }
};
// @lc code=end
