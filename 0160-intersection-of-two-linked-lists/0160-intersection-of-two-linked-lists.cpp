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

        ListNode* temp = headA;
        int countA=0,countB=0;
        while(temp){
            countA++;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            countB++;
            temp = temp->next;
        }

        cout<<countA<<","<<countB;

        ListNode* cur1 = headA;
        ListNode* cur2 = headB;

        int it = 0;
        if(countA>countB){
            it = countA-countB;
            for(int i = 0; i<it ; i++){
                cur1 = cur1->next;
            }
        }
        else{
            it = countB-countA;
            for(int i = 0; i<it ; i++){
                cur2 = cur2->next;
            }
        }

        while(cur1 && cur2){
            if(cur1 == cur2 ) return cur1;
            if(cur1->next == cur2->next) return cur1->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return new ListNode(0);

        
        
    }
};