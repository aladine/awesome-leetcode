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

// https://www.algoexpert.io/questions/Underscorify%20Substring
string underscorifySubstring(string str, string subStr) {
  int pos = str.find(subStr);
  vector<int> allpos;
  while (pos != string::npos) {
    allpos.push_back(pos);
    pos = str.find(subStr, pos);
  }

  if (allpos.empty()) {
    return str;
  }

  int S = subStr.length();
  int lastUnderscore = allpos.size() + subStr.length();
  for (int i = allpos.size() - 1; i >= 0; --i) {
    if (i + S > lastUnderscore) {
      lastUnderscore = i;
    } else {
      str = str.substr(0, i + S) + "_" + str.substr(i + S);
      lastUnderscore = i;
    }
  }
  return str;
}
// OR for string.find() function, remember to add nextStart = prevPos+1
// to concat string, use accumulate(all(vectorOfString),"")
// this problem is infact merging intervals.

// Time: O(n^2) | Space: O(n)
vector<int> longestIncreasingSubsequence(vector<int> A) {
  const int N = A.size();
  if (N == 0) {
    return {};
  }

  vector<int> lis;  // non decreasing subsequence
  for (auto& a : A) {
    auto pos = std::upper_bound(lis.begin(), lis.end(), a);
    if (pos != lis.end()) {
      lis[pos - lis.begin()] = a;
    } else {
      lis.push_back(a);
    }
  }
  return lis;
}

// Time: O(nlogn) | Space: O(n)
/*You can optimize your algorithm by taking a slightly different approach.
 * Instead of building the array mentioned in Hint #1, try building an array
 * whose indices represent lengths of subsequences and whose values represent
 * the smallest numbers in the input array that can end a subsequence of a given
 * length. Traverse the input array, and for each number determine what the
 * length L of the longest increasing subsequence ending with that number is;
 * store the position of that number at index L in the new array that you're
 * building. Find a way to use binary search to build this array.*/

int main(int argc, char* argv[]) {
  //
  return 0;
}
