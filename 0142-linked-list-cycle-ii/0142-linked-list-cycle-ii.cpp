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
    ListNode *detectCycle(ListNode *head) {

        int flag = INT_MIN;

        if(head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode* cur = head;

        while(cur && cur->val != flag){

            cur->val = flag;
            cur = cur->next;
        }

        return cur;

    }
};