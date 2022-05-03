#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef struct node* link;
typedef struct node{
    char symbol;
    int frequency;
    link left, right;
} node;

struct compare {
    bool operator()(link p, link q){
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<link, vector<link>, compare> PriorityQueue;


// void preorder(link root){
//     stack<link>s;
//     while(1){
//         while(root != NULL){
//             cout << root->symbol << ":" << root->frequency << " ";
//             s.push(root);
//             root = root->left;
//         }
//         if(s.empty()) break;
//         root = s.top(); s.pop();
//         root = root->right;
//     }
//     cout << "\n";
// }
// void inorder(link root){
//     stack<link>s;
//     while(1){
//         while(root != NULL){
//             s.push(root);
//             root = root->left;
//         }
//         if(s.empty()) break;
//         root = s.top(); s.pop();
//         cout << root->symbol << ":" << root->frequency << " ";
//         root = root->right;
//     }
//     cout << "\n";
// }

void preorder(link root){
    if(root !=NULL){
        cout << root->symbol << ":" << root->frequency << " "; 
        preorder(root->left);n 
        preorder(root->right);
    }
    return;
}

void inorder(link root){
    if(root !=NULL){
        inorder(root->left);
        cout << root->symbol << ":" << root->frequency << " "; 
        inorder(root->right);
    }
    return;
}


link create_node(char symbol, int frequency){
    link nNode = new node;
    //if(nNode) cout << "메모리성공!" <<"\n"; 
    //new 연산자가 node 크기 계산
    //->heap에 메모리 할당 후 주소 리턴  
    nNode->frequency = frequency;
    nNode->symbol = symbol;
    nNode->left = NULL;
    nNode->right = NULL;

    // static int temp = 0;
    // temp ++;
    // cout << temp << "번째" <<nNode->symbol << "\n";
    return nNode;
}

// void inputNode(int n, PriorityQueue& PQ){
//     vector<char> symbols(n+1);
//     link nNode =NULL;
//     int frequency;

//     //input symbols
//     for(int i=0; i<n; i++)
//         cin >> symbols[i];

//     //input frequencies & create_node
//     for (int i=0; i<n; i++){
//         //cout << "spot1" <<"\n";
//         cin >> frequency;
//         nNode = create_node(symbols[i],frequency);
        
//         PQ.push(nNode);
//     }
// }

void huffman(int n, PriorityQueue& PQ){
    for(int i=1; i <=n-1; i++){
        link p = PQ.top(); PQ.pop();
        link q = PQ.top(); PQ.pop();
        link r = create_node('+', p->frequency+q->frequency);
        r->left =p;
        r->right = q;
        PQ.push(r);
    }
}

void encode(link root, string code, vector<string>& encoder){
    if(root==NULL) return;
    if(root->left == NULL && root->right == NULL){ //leaf
        encoder[root->symbol - 'a'] = code; //(a = 65) a(index 0)~
        //cout << "spot " <<encoder[root->symbol - 'a'] << "\n";
    }
    else{
        encode(root->left , code+ "0", encoder); //append , '' x
        encode(root->right , code +"1", encoder); // string -> adress!!
    }

}

void decode(link root, link sRoot, string inputDecode, int index){ //index =0
    if(root==NULL) return;
    if(root->left == NULL && root ->right == NULL){
        cout << root->symbol;
        if(index >= inputDecode.size()) return; //인덱스 > inputDecode -> 종료
        decode(sRoot, sRoot, inputDecode, index); // 다시 루트에서 시작!!
        return;
    }
    if(inputDecode[index] == '0')
        decode(root->left,sRoot, inputDecode, index+1);
    else 
        decode(root->right,sRoot,inputDecode, index+1);
}


int main(void){
    int n; cin >> n;
    PriorityQueue PQ;
    vector<char> symbols(n+1);
    vector<int> frequecies(n+1);
    
    for(int i=1; i<=n; i++)
        cin >> symbols[i];
    for(int i=1; i<=n; i++)
        cin >> frequecies[i];

    for(int i=1; i<=n; i++)
        PQ.push(create_node(symbols[i],frequecies[i]));

    //inputNode(n,PQ);
    huffman(n,PQ);
    link root = PQ.top(); PQ.pop();


    int e; cin >> e; //encodes
    vector<string> inputcode(e+1);
    for(int i=0; i<e; i++)
        cin >> inputcode[i];

    int d; cin >> d; //decodes
    vector<string> inputDecode(d+1);
    for(int i=0; i<d; i++)
        cin >> inputDecode[i];
    
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";

    vector<string> encoder(n+1); string code ="";
    encode(root, code, encoder); //make encoder!!
    

    for(int i=0; i<e; i++){
        string t = inputcode[i];
        for(int j=0; j<t.size(); j++){
            cout << encoder[t[j] - 'a'];
        }
        cout << "\n";
    }
    
    for(int i=0; i<d; i++){
        int index =0;
        decode(root,root,inputDecode[i],index);
        if(i <d-1)
        cout << "\n";
    }

}
