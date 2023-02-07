/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Idea: use a map to track mapping between original node - new node pointer
    // Time complexity is O(n)
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mp;
        Node* p = head;
        Node* dummy = new Node(head->val);
        mp[head] = dummy;
        Node* curr = dummy;
        while(p != NULL){
            if(p->next != NULL){
                curr->next = new Node(p->next->val);
                mp[p->next] = curr->next;
                curr = curr->next;
            }
            p = p->next;
        }
        p = head;
        while(p != NULL){
            mp[p]->random = mp[p->random];
            p = p->next;
        }
        return dummy;
    }
};
