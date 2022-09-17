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
    // Idea: beacuse Number of Nodes in link A + Number of Nodes in link is a constance
    // let p1 walk through list A then walk through list B
    // also let p2 walk through list B then walk through list A at the same time
    // then p1 and p2 will reach the intersection node at the same time because their total steps are same.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(p1 != p2){
            if(p1 == NULL){
                p1 = headB;
            }
            else{
                p1 = p1->next;
            }
            if(p2 == NULL){
                p2 = headA;
            }
            else{
                p2 = p2->next;
            }
        }
        return p1;
    }
};