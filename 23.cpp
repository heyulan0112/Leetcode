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
    // Idea: re build comparator of priority heap
    // create a small heap for ListNode*
    // then always fetch curr smallest value node from heap (heap maintain nodes from all links)
    // if fetch on node from a link then let its next node from link gets into heap
    // Time complexity is O(MlogN) M is total nodes numbers in all links and N is the link numbers 
    struct comp{
        bool operator() (ListNode* l, ListNode* r){
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        ListNode* p = dummy;
        for(auto node:lists){
            if(node != NULL)
                pq.push(node);
        }
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            p->next = curr;
            p = p->next;
            if(curr->next != NULL){
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};