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

int shiftedBinarySearch(vector<int> array, int target) {
  int lo = 0, hi = array.size() - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (array[mid] == target) {
      return mid;
    }

    if (array[lo] <= array[mid]) {
      if (target >= array[lo] && target <= array[mid]) {
        hi = mid - 1;
      } else
        lo = mid + 1;
    } else if (array[mid] <= target && target <= array[hi]) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  if (array[lo] == target) {
    return lo;
  }
  if (array[hi] == target) {
    return hi;
  }
  return -1;
}

int main(int argc, char* argv[]) {
  //
  return 0;
}
