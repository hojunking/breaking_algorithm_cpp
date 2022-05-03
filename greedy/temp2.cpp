#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef struct node* node_ptr;
int cnt = 0;

typedef struct node
{
   char symbol; // the value of a character.
   int frequency; // the number of times the character is in the file.
   node_ptr left;
   node_ptr right;
} node_t;

struct compare
{
   bool operator()(node_ptr p, node_ptr q)
   {
      return p->frequency > q->frequency;
   }
};
typedef priority_queue<node_ptr, vector<node_ptr>, compare> PriorityQueue;

node_ptr create_node(char symbol, int frequency)
{
   node_ptr NewNode = new node_t;
   NewNode->symbol = symbol;
   NewNode->frequency = frequency;
   NewNode->left = NULL;
   NewNode->right = NULL;
   return NewNode;
}

void huffman(int n, PriorityQueue& PQ)
{
   for (int i = 1; i <= n - 1; i++)
   {
      node_ptr p = PQ.top(); PQ.pop();
      node_ptr q = PQ.top(); PQ.pop();
      node_ptr r = create_node('+', p->frequency + q->frequency);
      r->left = p;
      r->right = q;
      PQ.push(r);
   }
}

void preorder(node_ptr p, vector<char>& prec, vector<int>& pref)
{
   if (p)
   {
      prec.push_back(p->symbol);
      pref.push_back(p->frequency);
      preorder(p->left, prec, pref);
      preorder(p->right, prec, pref);
   }
}

void inorder(node_ptr p, vector<char>& inc, vector<int>& inf)
{
   if (p)
   {
      inorder(p->left, inc, inf);
      inc.push_back(p->symbol);
      inf.push_back(p->frequency);
      inorder(p->right, inc, inf);
   }
}

/*void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& encoder)
{
   if (root->symbol != '+')
   {
      vector<int> ret;
      ret.resize(code.size());
      copy(code.begin(), code.end(), ret.begin());
      encoder.insert(make_pair(root->symbol, ret));
   }
   else if (root != NULL)
   {
      code.push_back(0);
      encode(root->left, code, encoder);
      code.pop_back();
      code.push_back(1);
      encode(root->right, code, encoder);
      code.pop_back();
   }
}*/

map<char, string> encoder;
void encode(node_ptr p, string str)
{
   if (p == NULL)
      return;

   encode(p->left, str + '0');
   encode(p->right, str + '1');
   if (p->symbol != 0)
      encoder[p->symbol] = str;
}

vector<vector<string>> STR;
vector<vector<char>> STR2;
void decode(string str, node_ptr root)
{
   int i = 0;
   node_ptr j = root;
   while (str[i] != NULL)// 문자의 끝이 아닌 경우
   {
      if (str[i] == '0')// 문자가 0인 경우
         j = j->left;// 왼쪽 자식으로 이동

      else if (str[i] == '1')// 문자가 1인 경우
         j = j->right;// 오른쪽 자식으로 이동

      if (j->left == NULL && j->right == NULL) // 단말 노드인 경우
      {
         //char w = j->symbol;
         STR2[cnt].push_back(j->symbol);
         j = root;// 다시 원점으로
      }
      i++;
   }
   cnt++;
}




int main()
{
   int n;
   cin >> n;

   PriorityQueue PQ;

   vector<char> c; vector<int> f; vector<node_ptr> p;
   c.push_back(0); f.push_back(0); p.push_back(0);

   // For Traverse Node
   vector<char> prec; vector<int> pref;
   vector<char> inc; vector<int> inf;


   for (int i = 0; i < n; i++)
   {
      char symbol;
      cin >> symbol;
      c.push_back(symbol);
   }

   for (int i = 0; i < n; i++)
   {
      int frequency;
      cin >> frequency;
      f.push_back(frequency);
   }

   for (int i = 1; i <= n; i++)
   {
      node_ptr temp = create_node(c[i], f[i]);
      p.push_back(temp);
   }

   for (int i = 1; i <= n; i++)
      PQ.push(p[i]);

   huffman(n, PQ);

   node_ptr ptr = PQ.top();// ptr ir Root Node
                     // Huffman Tree 완성

   string str = "";
   encode(ptr, str);

   int num;
   cin >> num;
   STR.resize(num);
   for (int i = 0; i < num; i++)
   {
      string x;
      cin >> x;
      for (int j = 0; j < x.size(); j++)
      {
         STR[i].push_back(encoder[x[j]]);
      }
   }

   int num2;
   cin >> num2;
   STR2.resize(num2);
   for (int i = 0; i < num2; i++)
   {
      string x;
      cin >> x;
      decode(x, ptr);
   }

   preorder(ptr, prec, pref);
   inorder(ptr, inc, inf);

   // Print Preoreder
   for (int i = 0; i < prec.size(); i++)
   {
      if (i == 0)
         cout << prec[i] << ":" << pref[i];
      else
         cout << " " << prec[i] << ":" << pref[i];
   }
   cout << " ";
   cout << "\n";

   // Print Inoreder
   for (int i = 0; i < inc.size(); i++)
   {
      if (i == 0)
         cout << inc[i] << ":" << inf[i];
      else
         cout << " " << inc[i] << ":" << inf[i];
   }
   cout << " ";
   cout << "\n";


   for (vector<string> vec: STR)
   {
      for (string n: vec)
         cout << n;

      cout << "\n";
   }

   for (vector<char> vec: STR2)
   {
      for (char n: vec)
         cout << n;

      cout << "\n";
   }

   return 0;
}