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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == nullptr || head->next == nullptr ) return head;
        int n = 0;

        ListNode* cur = head;
        while(cur)
        {
            cur = cur->next;
            n++;
        }
        int eff_k = k%n;
        
        eff_k = n - eff_k;
        cout<<eff_k;

        cur = head->next;
        ListNode* prev = head;
        while(eff_k>1){
            prev = cur;
            cur = cur->next;
            eff_k--;
        }

        prev->next = nullptr;

        ListNode* head_new = cur;

        if(cur == nullptr) return head;
        while(cur->next != nullptr){
            cur = cur->next;
        }

        cur->next = head;
        return head_new;
        
    }
};