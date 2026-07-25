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
    ListNode* middleNode(ListNode* head) {
        
        int count = 0;

        if(head->next == nullptr){
            return head;
        }

        ListNode* mover = head;


        while(mover){
            mover = mover->next;
            count++;
        }
        
        int mid = count%2 != 0 ? (count+1)/2 : (count/2)+1;
        mover = head;

        while(mid>1){
            mover = mover->next;
            mid--;
        }

        return mover;
    }
};