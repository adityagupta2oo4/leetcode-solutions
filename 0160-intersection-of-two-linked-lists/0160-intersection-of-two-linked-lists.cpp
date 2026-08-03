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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        ListNode* cur1 = headA;
        ListNode* cur2 = headB;

        
        int countA=0,countB=0;
        
        while(cur1 || cur2){
            if(cur1){
                countA++;
                cur1=cur1->next;
            }
            
            if(cur2){
                countB++;
                cur2 = cur2->next;
            }
        }

        cur1 = headA;
        cur2 = headB;

        bool flagA = countA>countB ? true : false;
        int it = flagA ? countA - countB : countB - countA;

        ListNode* temp = flagA ? cur1 : cur2;

        for(int i = 0 ; i<it ; i++) temp = temp->next;

        if(flagA) cur1 = temp;
        else cur2 =temp;


        while(cur1 && cur2){
            //edge case of if we have already read
            if(cur1 == cur2 ) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return nullptr;

        
        
    }
};