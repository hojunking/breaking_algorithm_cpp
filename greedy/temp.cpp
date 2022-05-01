#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
using namespace std;

int n;
string str;
string codeword[26]; // for lowercase
string CODEWORD[26]; // for uppercase

typedef struct node* nodePointer;
typedef struct node{
  char key;
  int frequency;
  nodePointer left, right;
} node;

struct compare { bool operator()(nodePointer p, nodePointer q) { return p->frequency > q->frequency; } };
typedef priority_queue<nodePointer, vector<nodePointer>, compare> PriorityQueue;

void preorder(nodePointer root){
  if(root == NULL) return;
  cout << root->key << ":" << root->frequency << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(nodePointer root){
  if(root == NULL) return;
  inorder(root->left);
  cout << root->key << ":" << root->frequency << " ";
  inorder(root->right);
}

void encode(nodePointer root, string code){
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL) {
    if(root->key >= 'a') codeword[root->key - 'a'] = code;
    else CODEWORD[root->key - 'A'] = code;
  }
  else {
    encode(root->left, code + "0");
    encode(root->right, code + "1");
  }
}

void decode(nodePointer root, nodePointer ROOT, string code, int idx){
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL){
    cout << root->key;
    if(idx >= code.length()) return;
    decode(ROOT, ROOT, code, idx);
    return;
  }
  switch(code[idx]){
    case '0':
      decode(root->left, ROOT, code, idx + 1);
      break;
    case '1': 
      decode(root->right, ROOT, code, idx + 1);
      break;
  }
}

int main(){

  cin >> n;
  vector<char> S(n+1);    // String
  vector<int> F(n+1);     // Frequency
  PriorityQueue pq;       // priority queue for making tree

  for(int i=1; i<=n; i++) cin >> S[i];
  for(int i=1; i<=n; i++) cin >> F[i];
  
  // initialize
  for(int i=1; i<=n; i++){
    nodePointer t = new node();
    t->key = S[i];
    t->frequency = F[i];
    t->left = t->right = NULL;
    pq.push(t);
  }
  
  // make Huffman tree
  for(int i=1; i<n; i++){
    nodePointer a = pq.top(); pq.pop();
    nodePointer b = pq.top(); pq.pop();
    nodePointer ab = new node();
    ab->key = '+';
    ab->frequency = a->frequency + b->frequency;
    ab->left = a;
    ab->right = b;
    pq.push(ab);
  }

  nodePointer root = pq.top(); pq.pop();

  // traverse
  preorder(root); cout << "\n";
  inorder(root); cout << "\n";

  // make Huffman Code
  encode(root, "");

  // encode
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> str;
    for(int j=0; j<str.size(); j++){
      if(str[j] >= 'a') cout << codeword[str[j] - 'a'];
      else cout << CODEWORD[str[j] - 'A'];
    }
    cout << "\n";
  }

  // decode
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> str;
    decode(root, root, str, 0); cout << (i != n-1 ? "\n" : "");
  }

  return 0;
}