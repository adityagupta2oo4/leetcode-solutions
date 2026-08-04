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

        //edge case
        if(head == nullptr ) return false;
        ListNode* cur = head;
        int x = 1000000 ;//choosing value which is out of range of  Node.val just to mark it visited

        while(cur){

            if (cur->next && cur->next->val == x) //checking curr-> nest exist or not then accessing its value
                return true;
            cur->val = x;
            cur = cur->next;
        }
        
        return false;
    }
};