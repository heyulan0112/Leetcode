/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Idea: using find the last kth node in list template to solve
    // need to add a dummy node to handel special case - deleting the origin head node
    // use template to find out the last (n+1)th node in link list
    // then make this node->next = node->next->next
    // Time complexity is O(n)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* node = FindLastK(dummy,n+1);
        node->next = node->next->next;
        return dummy->next;
    }
    
    ListNode* FindLastK(ListNode* head, int n){
        ListNode* p1 = head;
        for(int i=0; i<n; i++){
            p1 = p1->next;
        }
        ListNode* p2 = head;
        while(p1 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};