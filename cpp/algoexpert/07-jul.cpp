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

bool checkSameBST(vector<int>& arrayOne, vector<int>& arrayTwo, int st,
                  int ed) {
  if (st > ed) return true;
  if (arrayOne[st] != arrayTwo[st]) {
    return false;
  }
  int h = ed;
  for (int i = st + 1; i < h + 1; ++i) {
    while (h > i && arrayOne[h] > arrayOne[st]) {
      h--;
    }
    if (arrayOne[i] > arrayOne[st]) {
      swap(arrayOne[i], arrayOne[h]);
    }
    if (i == h) break;
  }

  int hb = ed;
  for (int i = st + 1; i < hb + 1; ++i) {
    while (hb > i && arrayTwo[hb] > arrayTwo[st]) {
      hb--;
    }
    if (arrayTwo[i] > arrayTwo[st]) {
      swap(arrayTwo[i], arrayTwo[hb]);
    }
    if (i == hb) break;
  }
  if (h != hb) return false;
  return checkSameBST(arrayOne, arrayTwo, st + 1, h) &&
         checkSameBST(arrayOne, arrayTwo, h + 1, ed);
}

// Time: O(n^2) | Space: O(1)
bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  if (arrayOne.empty() || arrayTwo.empty() ||
      arrayOne.size() != arrayTwo.size() || arrayOne[0] != arrayTwo[0]) {
    return false;
  }

  return checkSameBST(arrayOne, arrayTwo, 0, arrayOne.size() - 1);
}

// https://www.algoexpert.io/questions/Right%20Smaller%20Than
vector<int> rightSmallerThan(vector<int> array) {
  const int N = array.size();
  vector<int> res(N, 0);
  // brute force O(n^2)
  // let's sort
  vector<int> curr;
  for (int i = N - 1; i >= 0; --i) {
    int d = array[i];
    auto it = lower_bound(curr.begin(), curr.end(), d);
    res[i] = it - curr.begin();
    curr.insert(it, d);
  }
  return res;
}

int main(int argc, char* argv[]) {
  //
  return 0;
}
