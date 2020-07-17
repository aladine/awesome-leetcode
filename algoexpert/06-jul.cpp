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

// https://www.algoexpert.io/questions/Boggle%20Board
struct Trie {
  Trie* child[128];
  bool end;
  Trie() : end(false) {
    for (int i = 0; i < 128; i++) child[i] = nullptr;
  };
};

void addWord(Trie*& r, string w) {
  Trie* tmp = r;
  for (auto c : w) {
    int pos = c;
    if (tmp->child[pos] == nullptr) {
      tmp->child[pos] = new Trie();
    }
    tmp = tmp->child[pos];
  }
  tmp->end = true;
}

vector<string> ans;
set<pair<int, int>> vis;
void dfs(vector<vector<char>> grid, int a, int b, Trie* r, string curr) {
  char c = grid[a][b];
  cout << a << b << c << " " << curr << endl;
  if (r->child[c] == nullptr) return;
  // if (vis.count({a, b}) == 1)  return;
  r = r->child[c];

  for (auto ele : vis) cout << ele.first << ":" << ele.second << endl;
  curr += c;

  if (r->end) {
    ans.push_back(curr);
  }
  const int R = grid.size();
  const int C = grid[0].size();
  vis.insert({a, b});
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      int x = a + i, y = b + j;
      if (x >= 0 && x < R && y >= 0 && y < C) {
        if (vis.count({x, y}) == 0) {
          dfs(grid, x, y, r, curr);
        }
      }
    }
  }
  vis.erase({a, b});
}

vector<string> boggleBoard(vector<vector<char>> grid, vector<string> words) {
  const int R = grid.size();
  if (R == 0) {
    return {};
  }
  const int C = grid[0].size();
  Trie* r = new Trie();

  for (auto w : words) {
    addWord(r, w);
  }

  ans.clear();
  vis.clear();
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      vis.clear();
      dfs(grid, i, j, r, "");
    }
  }

  sort(ans.begin(), ans.end());
  auto it = std::unique(ans.begin(), ans.end());
  ans.erase(it, ans.end());

  return ans;
}

// https://www.algoexpert.io/questions/Rectangle%20Mania
struct Point {
  int x;
  int y;
};

int rectangleMania(vector<Point> coords) {
  const int C = coords.size();
  int minx = INT_MAX, miny = INT_MAX;
  for (auto coord : coords) {
    minx = min(minx, coord.x);
    miny = min(miny, coord.y);
  }
  vector<bitset<201>> matrix(201, 0);
  for (auto coord : coords) {
    matrix[coord.x - minx].set(coord.y - miny);
  }
  int ans = 0;
  for (int i = 1; i < 201; ++i) {
    for (int j = 0; j < i; ++j) {
      int k = (matrix[i] & matrix[j]).count();
      ans += k * (k - 1) / 2;
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  //
  return 0;
}
