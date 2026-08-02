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
        
        ListNode* prev = new ListNode(0);
        while(node->next != nullptr){
            node->val = node->next->val;
            
            if(node->next->next == nullptr) prev = node;
            node = node->next;
        }

        prev->next = nullptr;

        delete node;

        
        
    }
};