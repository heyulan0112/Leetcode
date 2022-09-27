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
    // Idea: when it comes to add, in most interview, should implement add operation by myself
    // Tims and Space complexity is O(n)
    vector<int> add(vector<int> n1, vector<int> n2){
        int i = n1.size()-1, j = n2.size()-1;
        vector<int> res;
        int carry = 0;
        while(i>=0 && j>=0){
            int cur = n1[i] + n2[j] + carry;
            carry = 0;
            if(cur >= 10){
                carry = 1;
                cur -= 10;
            }
            res.push_back(cur);
            i--;
            j--;
        }
        while(i>=0){
            int cur = n1[i] + carry;
            carry = 0;
            if(cur >= 10){
                carry = 1;
                cur -= 10;
            }
            res.push_back(cur);
            i--;
        }
        while(j>=0){
            int cur = n2[j] + carry;
            carry = 0;
            if(cur >= 10){
                carry = 1;
                cur -= 10;
            }
            res.push_back(cur);
            j--;
        }
        if(carry == 1){
            res.push_back(1);
        }
        return res;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> n1;
        vector<int> n2;
        ListNode* p = l1;
        while(p != NULL){
            n1.push_back(p->val);
            p = p->next;
        }
        p = l2;
        while(p != NULL){
            n2.push_back(p->val);
            p = p->next;
        }
        vector<int> sum;
        sum = add(n1,n2);
        
        ListNode* dummy = new ListNode(-1);
        p = dummy;
        for(int i=sum.size()-1;i>=0;i--){
            ListNode* node = new ListNode(sum[i]);
            p->next = node;
            p = p->next;
        }
        return dummy->next;
    }
};