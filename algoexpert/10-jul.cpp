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

class ContinuousMedianHandler {
 public:
  double median;
  priority_queue<int, vector<int>> maxH;
  priority_queue<int, vector<int>, std::greater<int>> minH;

  void insert(int number) {
    if (maxH.empty() || number < maxH.top())
      maxH.push(number);
    else
      minH.push(number);

    if (minH.size() > maxH.size() + 1) {
      auto ele = minH.top();
      minH.pop();
      maxH.push(ele);
    } else if (maxH.size() > minH.size() + 1) {
      auto ele = maxH.top();
      maxH.pop();
      minH.push(ele);
    }

    if (minH.size() > maxH.size())
      median = minH.top();
    else if (maxH.size() > minH.size())
      median = maxH.top();
    else
      median = 0.5 * ((double)minH.top() + (double)maxH.top());
  }

  double getMedian() { return median; }
};

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
  vector<int> res = arrays[0];
  for (int i = 1; i < arrays.size(); ++i) {
    int mid = res.size();
    copy(arrays[i].begin(), arrays[i].end(), std::back_inserter(res));
    inplace_merge(res.begin(), res.begin() + mid, res.end());
  }
  return res;
}

class MinHeap {
 public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(&vector); }

  vector<int> buildHeap(vector<int> *vector) {
    heap = *vector;
    for (int i = vector->size() - 1; i >= vector->size() / 2; --i) {
      siftUp(i, &heap);
    }
    return heap;
  }

  int getParentIndex(int idx) { return (idx - 1) / 2; }

  void siftDown(int currentIdx, int endIdx, vector<int> *heap) {
    swap(heap[currentIdx], heap[endIdx]);
  }

  void siftUp(int currentIdx, vector<int> *heap) {
    swap(heap[currentIdx], heap[getParentIndex(currentIdx)]);
  }

  int peek() {
    if (!heap.empty()) {
      return heap[0];
    }
    return -1;
  }

  int remove() {
    if (heap.empty()) return -1;
    int v = peek();

    heap[0] = heap.back();
    heap.pop_back();
    int idx = 0;
    while (idx < heap.size()) {
      int cid = 2 * idx + 1;
      if (heap[idx] > heap[cid]) {
        siftDown(idx, cid, &heap);
      }
      idx = cid;
    }
    return v;
  }

  void insert(int value) {
    heap.push_back(value);
    int idx = heap.size() - 1;
    while (idx) {
      if (heap[idx] < heap[getParentIndex(idx)]) {
        siftUp(idx, &heap);
      }
      idx = getParentIndex(idx);
    }
  }
};

class LRUCache {
 public:
  struct KVPair {
    string k;
    int v;
  };
  int maxSize;
  unordered_map<string, list<KVPair>::iterator> m;
  list<KVPair> l;

  LRUCache(int maxSize) { this->maxSize = maxSize > 1 ? maxSize : 1; }

  void insertKeyValuePair(string key, int value) {
    auto val = getValueFromKey(key);
    if (val != NULL) {
      m[key]->v = value;
      return;
    }

    l.push_front({key, value});
    m[key] = l.begin();
    while (l.size() > maxSize) {
      auto ele = l.back();
      l.pop_back();
      m.erase(ele.k);
    }
  }

  int *getValueFromKey(string key) {
    if (m.count(key)) {
      auto it = m[key];
      l.push_front(*it);
      l.erase(it);
      m[key] = l.begin();
      return &((*it).v);
    }
    return NULL;
  }

  string getMostRecentKey() {
    if (!l.empty()) {
      return l.front().k;
    }
    return "";
  }
};

int main(int argc, char *argv[]) {
  //
  return 0;
}
