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
    // Idea: because numer are too large so cannot just use + operator
    // need to use manual add just write add function myself
    // need to handle carry and l1 l2 different length
    // also need to handle the last remaining carry (if carry == 1),
    // after traversing all digits in l1 and l2
    // time complexity is O(n)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> digits1;
        vector<int> digits2;
        int carry = 0;
        ListNode* root = new ListNode(-1);
        ListNode* curr = root;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(carry == 1){
                carry = 0;
            }
            if(sum >= 10){
                carry = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(carry == 1){
                carry = 0;
            }
            if(sum >= 10){
                carry = 1;
            }
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(carry == 1){
                carry = 0;
            }
            if(sum >= 10){
                carry = 1;
            }
            l2 = l2->next;
        }
        if(carry == 1){
            curr->next = new ListNode(1);
        }
        return root->next;
    }
};