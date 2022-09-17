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
    // Idea: similar to array remove duplicate template
    // use slow fast two ppinters to solve it
    // Time complexity is O(n)
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            if(fast->val != slow->val){
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // remember to delete every node after slow pointer at the end
        // in order to handle the tail special case
        ListNode* d = slow->next;
        slow->next = NULL;
        delete d;
        return head;
    }
};