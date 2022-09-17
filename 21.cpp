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
    // Idea: add a virtual head node dummy to avoid handling special case 
    // merge two string classic template
    // Time complexity O(n)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* p = dummy;
        while(p1!=NULL && p2!=NULL){
            // this is <= because p1 may have same value as p2
            if(p1->val <= p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else if(p2->val < p1->val){
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1 != NULL){
            p->next = p1;
        }
        if(p2 != NULL){
            p->next = p2;
        }
        return dummy->next;
    }
};