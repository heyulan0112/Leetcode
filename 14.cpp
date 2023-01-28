// class Node{
// public:
//     char val;
//     vector<Node*> children;
//     Node(){
//         children = vector<Node*>(26,NULL);
//     }
//     Node(char v){
//         val = v;
//         children = vector<Node*>(26,NULL);
//     }
// };

// Node* insert(Node* root, string& s, int i){
//     if(i<s.size()){
//         root->children[s[i]-'a'] = new Node(s[i]);
//         insert(root->children[s[i]-'a'],s,i+1);
//     }
//     return root;
// }

// void explore(Node* root, string& s, int i, string& ans){
//     if(root == NULL || i>=s.size()){
//         return;
//     }
//     char c = s[i];
//     if(root->children[c-'a'] != NULL){
//         ans += c;
//         explore(root->children[c-'a'],s,i+1,ans);
//     }
// }

class Solution {
public:
    // Idea: enumerate
    // Time complexity is O(no. strings in strs * min length of strings in strs)
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size() || strs[j][i] != strs[0][i]){
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
