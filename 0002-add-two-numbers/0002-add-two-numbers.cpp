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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //exception cases

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        int carry_flag = 0;

        // pointer for traversing the given 2 LL

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        //to store the result in new LL

        ListNode* dummy = new ListNode(0);
        ListNode* curr3 = dummy;

        // more cleaner

        while(curr1 || curr2 || carry_flag){

            int sum = carry_flag;

            if(curr1){
                sum += curr1->val;
                curr1 = curr1->next;
            }
            
            if(curr2){
                sum += curr2->val;
                curr2 = curr2->next;
            }

            curr3->next = new ListNode(sum%10);
            curr3 = curr3->next;
            carry_flag = sum/10;

        }

        return dummy->next;

        
    }
};