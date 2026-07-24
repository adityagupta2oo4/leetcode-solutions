/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *
 xt) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // we are considering 3 nodes say befor current after

        //intiaaly

        ListNode* prev = nullptr;
        ListNode* curr = head;

        if(head == nullptr){
            return head;
        }

        ListNode* nex = head->next; // you never know weather it singl element LL


        while(nex){

            curr->next = prev;
            ListNode* temp = nex->next;
            nex->next = curr;

            prev = curr;
            curr = nex;
            nex = temp;


        }
        

        return curr;
    }
    
   
};