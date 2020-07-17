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

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  vector<vector<int>> res;
  sort(disks.begin(), disks.end(),
       [](const vector<int>& a, const vector<int>& b) {
         if (a[0] == b[0]) return a[1] < b[1];
         return a[0] < b[0];
       });
  const int N = disks.size();
  vector<int> lis(N);

  vector<int> parents(N, -1);
  int idxMax = 0;
  lis[0] = disks[0][2];
  for (int i = 1; i < N; ++i) {
    lis[i] = disks[i][2];
    for (int j = 0; j < i; ++j) {
      if (disks[j][0] < disks[i][0] && disks[j][1] < disks[i][1] &&
          disks[j][2] < disks[i][2] && lis[i] < lis[j] + disks[i][2]) {
        lis[i] = lis[j] + disks[i][2];
        parents[i] = j;
      }
    }
    if (lis[idxMax] < lis[i]) {
      idxMax = i;
    }
  }

  while (idxMax != -1) {
    res.push_back(disks[idxMax]);
    idxMax = parents[idxMax];
  }
  reverse(res.begin(), res.end());

  return res;
}

int main(int argc, char* argv[]) {
  //
  return 0;
}
