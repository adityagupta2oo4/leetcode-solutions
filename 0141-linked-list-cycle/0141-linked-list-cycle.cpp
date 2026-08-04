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
    bool hasCycle(ListNode *head) {
        
        // using recurscion
        if(head == nullptr ) return false;

        if(head->val == INT_MAX) return true;
        head->val = INT_MAX;
        
        return hasCycle(head->next);
    }
};