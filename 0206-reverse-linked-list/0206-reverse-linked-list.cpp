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


        while(nex){  // reached end of list

            // move the curr to previous
            curr->next = prev;
            // now before moving the next to point curr we need to store the nex->next so we can go frwd 
            ListNode* temp = nex->next;
            //making nex to point curr
            nex->next = curr;

            prev = curr;
            curr = nex;
            nex = temp;


        }
        

        return curr;
    }
    
   
};