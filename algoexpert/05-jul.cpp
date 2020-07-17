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

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  // BinaryTree *parent;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

int dfsPathSum(BinaryTree* root, int& maxPath){
  if (root==nullptr) {
    return 0;
  }
  int l = dfsPathSum(root->left, maxPath);
  int r = dfsPathSum(root->right, maxPath);
  maxPath = max(maxPath, l+r+root->value);
  return max(0, max(l+root->value, r+root->value));
}

int maxPathSum(BinaryTree tree) {
  int ans = INT_MIN;
  dfsPathSum(&tree, ans);
  return ans;
}

void iterativeInOrderTraversal(BinaryTree* tree,
                               void (*callback)(BinaryTree* tree)) {
  stack<BinaryTree*> st;
  if (tree == NULL) return;
  while (tree || !st.empty()) {
    while (tree) {
      st.push(tree);
      tree = tree->left;
    }
    tree = st.top();
    st.pop();
    callback(tree);
    tree = tree->right;
  }
}
// Time: O(n) | Space: O(h)
// OR: when there is parent pointer,
// we could reduce space complexity to O(1)
// Using prevNode and currNode

void connectNodes(BinaryTree* tmp, BinaryTree* root){
   tmp->right = root;
    root->left = tmp;
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
  stack<BinaryTree*> st;
	if(root==NULL) return root;
  BinaryTree* dummy = new BinaryTree(0);
  BinaryTree* tmp = dummy;
	while(root || !st.empty()){
    while(root){
      st.push(root);
      root = root->left;
    }
    root = st.top();
    st.pop();
   connectNodes(tmp, root);
    tmp = tmp->right;
    root = tmp->right;
	}

  dummy = dummy->right;
	dummy->left = nullptr;
	return dummy;
}

// https://www.algoexpert.io/questions/Right%20Sibling%20Tree
BinaryTree* rightSiblingTree(BinaryTree* root) { return root; }

bool hasSingleCycle(vector<int> array) {
  const int N = array.size();
  for (int i = 0; i < N; ++i) {
    while (array[i] < 0) {
      array[i] += N;
    }
  }

  int i = 0;
  int counter = 0;
  while (array[i] > 0) {
    counter++;
    array[i] = -array[i];
    i = (i + array[i]) % N;
  }
  return counter == N;

  return true;
}

class AncestralTree {
 public:
  char name;
  AncestralTree* ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree*> descendants);
};

AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor,
                                         AncestralTree* descendantOne,
                                         AncestralTree* descendantTwo) {
  // find depth;
  AncestralTree* tmp = descendantOne;
  int d1 = 0, d2 = 0;
  while (tmp != topAncestor) {
    d1++;
    tmp = tmp->ancestor;
  }
  tmp = descendantTwo;
  while (tmp != topAncestor) {
    d2++;
    tmp = tmp->ancestor;
  }
  tmp = d1 < d2 ? descendantTwo : descendantOne;
  for (int i = 0; i < abs(d1 - d2); ++i) {
    tmp = tmp->ancestor;
  }

  if (d1 < d2) {
    descendantTwo = tmp;
  } else
    descendantOne = tmp;
  while (descendantOne != descendantTwo) {
    descendantOne = descendantOne->ancestor;
    descendantTwo = descendantTwo->ancestor;
  }

  return descendantOne;
}

int main(int argc, char* argv[]) {
  //
  return 0;
}
