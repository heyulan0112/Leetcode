// Child relationship is one sigle place of all digits
// node value is current total n or string if choose this single place
class Node{
public:
    vector<Node*> child;
    int data;
    bool isWord;
    Node(){
        child = vector<Node*>(10,NULL);
        data = 0;
        isWord = false;
    }
    Node(int val){
        child = vector<Node*>(10,NULL);
        data = val;
        isWord = false;
    }
};

class Solution {
public:
    void insert(Node* root, int n){
        string n_str = to_string(n);
        Node* p = root;
        for(char c:n_str){
            int curr = c-'0';
            if(p->child[curr] == NULL){
                p->child[curr] = new Node(curr);
            }
            p = p->child[curr];
        }
        p->data = n;
        p->isWord = true;
    }

    void explore(vector<int>& ans, Node* root){
        if(root->isWord == true){
            ans.push_back(root->data);
        }
        for(int i=0;i<=9;i++){
            if(root->child[i]!=NULL){
                explore(ans,root->child[i]);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        Node* root = new Node();
        for(int i=1;i<=n;i++){
            insert(root,i);
        }
        explore(ans,root);
        return ans;
    }
};