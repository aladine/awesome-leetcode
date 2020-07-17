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

vector<int> buildKMP(string p){
	const int P = p.length();
	vector<int> prefix(P);
  prefix[0] = 0;
  int j = 0;
  for (int i = 1; i < P; ++i) {
    j = prefix[i-1];
    while(p[i]!=p[j] && j > 0) j = prefix[j-1];
    if (p[i]==p[j]) {
      j++;
    }
    prefix[i] = j;
  }
	return prefix;
}

bool knuthMorrisPrattAlgorithm(string str, string substr) {
  if (str.length() < substr.length()) {
    return false;
  }
  vector<int> prefix = buildKMP(substr+ '#' + str);
  for (int i = substr.length()+1; i < prefix.size(); ++i) {
    if (prefix[i] == substr.length()) {
      return true;
    }
  }
  return false;
}
// Test: abc [], abc a, xyz xyz,

string shortenPath(string path) {
  stringstream ss(path);
  string token;
  vector<string> st;
  bool startAtRoot = path[0] == '/';
  while (getline(ss, token, '/')) {
    if (token == "" || token == ".") continue;
    if (token == "..") {
      if (!st.empty() && st.back() != "..") {
        st.pop_back();
      } else if (!startAtRoot)
        st.push_back(token);
    } else
      st.push_back(token);
  }

  string res = startAtRoot ? "/" : "";
  for (auto ele : st) {
    res += ele + "/";
  }
  if (!st.empty()) res.pop_back();
  /* Use ostringstream
  ostringstream oss;
  if (i!=0) {
  oss <<st[i];
  }
  return oss.str();
  */
  return res;
}

// https://www.algoexpert.io/questions/Palindrome%20Partitioning%20Min%20Cuts
// Time: O(n^3) | Space: O(n^2)
vector<vector<int> > dp;
bool isPalin(string s, int st, int ed){
  for(;st<ed; st++, ed--){
    if (s[st] != s[ed]) {
      return false;
    }
  }
  return true;
}


int palindromeCuts(string s, int st, int ed){
  if (dp[st][ed]!= -1) {
    return dp[st][ed];
  }
	dp[st][ed] = ed-st;
	if(isPalin(s, st, ed)){
		dp[st][ed] = 0;
		return dp[st][ed];
	}
  for (int i = st+1; i <= ed; ++i) {
		if(isPalin(s, st, i-1))
    dp[st][ed] = min(dp[st][ed],1+ palindromeCuts(s, i, ed) );
  }

  return dp[st][ed];
}

int palindromePartitioningMinCuts(string str) {
  const int N = str.size();
  dp.assign(N, vector<int> (N, -1));
  for (int i = 0; i < N; ++i) {
    dp[i][i] = 0;
  }
  return palindromeCuts(str, 0, N-1);
}
// OR: replace dp to vector<int> (N, INT_MAX) with O(n) space
// to calc palindrom, can use memo



int main(int argc, char* argv[]) {
  //
  return 0;
}
