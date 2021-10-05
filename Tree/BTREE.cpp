#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,n) for(int i=a;i<n;i++)
#define vi vector<ll>
#define vp vector<pi>
#define mpi unordered_map<ll,ll>
#define si unordered_set<ll>
#define str string
#define st stack<ll> 
#define q queue<ll> 
#define pi pair<ll,ll>
#define mps unordered_map<str,ll>
#define mod 1000000007

class Node {
  int *keys;
  int t;
  Node **C;
  int n;
  bool leaf;

   public:
  Node(int _t, bool _leaf);

  void insertNonFull(int k);
  void splitChild(int i, Node *y);
  void traverse();

  friend class BTree;
};

class BTree {
  Node *root;
  int t;

   public:
  BTree(int _t) {
    root = NULL;
    t = _t;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  void insert(int k);
};

Node::Node(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new Node *[2 * t];

  n = 0;
}

// Traverse the nodes
void Node::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout << " " << keys[i];
  }

  if (leaf == false)
    C[i]->traverse();
}

// Insert the node
void BTree::insert(int k) {
  if (root == NULL) {
    root = new Node(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      Node *s = new Node(t, false);

      s->C[0] = root;

      s->splitChild(0, root);

      int i = 0;
      if (s->keys[0] < k)
        i++;
      s->C[i]->insertNonFull(k);

      root = s;
    } else
      root->insertNonFull(k);
  }
}

// Insert non full condition
void Node::insertNonFull(int k) {
  int i = n - 1;

  if (leaf == true) {
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }

    keys[i + 1] = k;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i] > k)
      i--;

    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);

      if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k);
  }
}

// split the child
void Node::splitChild(int i, Node *y) {
  Node *z = new Node(y->t, y->leaf);
  z->n = t - 1;

  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];

  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  y->n = t - 1;
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];

  C[i + 1] = z;

  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  keys[i] = y->keys[t - 1];
  n = n + 1;
}

int main() {
  BTree t(3);
  t.insert(8);
  t.insert(9);
  t.insert(10);
  t.insert(11);
  t.insert(15);
  t.insert(16);
  t.insert(17);
  t.insert(18);
  t.insert(20);
  t.insert(23);

  cout << "The B-tree is: ";
  t.traverse();
}