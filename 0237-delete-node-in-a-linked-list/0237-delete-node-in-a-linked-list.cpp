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
    void deleteNode(ListNode* node) {
        
        ListNode* prev = node;
        // prev and node at same point


        node->val = node->next->val;

        node = node->next;
        //[4,1,1,9] [4,prev(1),node(1),9]

        //normaly delete 

        prev->next = node->next;
        

        delete node;

        
        
    }
};