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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // my-approach

        // edge case 
        if(head == NULL || n == 0 ) return head; // empty
        
        //converting the problem from last kth to removing kth

        int count = 0;
        ListNode* curr = head;

        while(curr){
            count++;
            curr = curr->next;
        }

        cout<<count;

        int k = count - n;

        // if it's head
        if(k == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // if it's tail and kth

            
        curr = head;
        ListNode* prev;

        while(k>0){
            prev = curr;
            curr = curr->next;
            k--;
        }

        ListNode* toDel = curr;
        prev->next = curr->next;
        delete toDel;
    



        return head;
        
    }
};