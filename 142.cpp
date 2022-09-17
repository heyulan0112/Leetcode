/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Idea: using different speed two pointer template
    // but also add a same speed part after detecting a loop to reset them to loop start point
    // Time complexity is O(n)
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1!=NULL && p1->next!=NULL){
            p1 = p1->next->next;
            p2 = p2->next;
            if(p1 == p2)
                break;
        }
        if(p1 == NULL || p1->next == NULL)
            return NULL;
        p2 = head;
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};