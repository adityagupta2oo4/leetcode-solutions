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
    bool isPalindrome(ListNode* head) {

        int count = 0;
        if(!head || !head->next) return true;
        ListNode* cur = head;

        while(cur){
            cur = cur->next;
            count++;
        }

        int n = count%2 ? (count/2)+1 : (count+1)/2;


        ListNode* prev = head;
        cur = head->next;
        while(n>0){
            prev = cur;
            cur = cur->next;
            n--;
        }

        prev->next = nullptr;
        ListNode* temp;
        while(cur){
            
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;

        }

        cur = prev;
        temp = head;
        while(cur){

            if(cur->val != temp->val) return false;
            cur = cur->next;
            temp = temp->next;

        }
        
        return true;
        



    }
};