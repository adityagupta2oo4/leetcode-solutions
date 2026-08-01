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

        ListNode* dummy = new ListNode();
        ListNode* curr3 = dummy;

        // adding the number 

        while(curr1 && curr2){

            int add_val = curr1->val + curr2->val + carry_flag;

            curr3->next = new ListNode(add_val%10);

            carry_flag = add_val/10;

            curr1 = curr1->next;
            curr2 = curr2->next;
            curr3 = curr3->next;
        }

        //now it's not neccarry that the size of the l1 and l2 are same

        while(curr1){

            int add_val = curr1->val + carry_flag;

            curr3->next = new ListNode(add_val%10);

            carry_flag = add_val/10;
            curr1 = curr1->next;
            curr3 = curr3->next;

        }

        while(curr2){

            int add_val = curr2->val + carry_flag;

            curr3->next = new ListNode(add_val%10);

            carry_flag = add_val/10;
            curr2 = curr2->next;
            curr3 = curr3->next;

        }

        // last check weather carry has become 0 or not

        if(carry_flag != 0) curr3->next = new ListNode(carry_flag);


        return dummy->next;

        
    }
};