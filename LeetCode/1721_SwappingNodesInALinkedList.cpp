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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *low = head, *high = head;
        ListNode *curr = head;
        
        int cnt = 1;
        while(curr != NULL){
            if(cnt < k){
                low = low->next;
            }
            if(cnt > k){
                high = high->next;
            }
            curr = curr->next;
            cnt++;
        }
        int tmp = low->val;
        low->val = high->val;
        high->val = tmp;
        
        return head;
    }
};
