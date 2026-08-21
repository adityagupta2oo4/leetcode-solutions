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
        while(cur->next != nullptr)
        {
            cur = cur->next;
            n++;
        }

        cur->next = head;
        int eff_k = k%(n+1);
        
        eff_k = (n+1)- eff_k;
        cout<<eff_k;

        cur = head;

        while(eff_k>1){
            cur = cur->next;
            eff_k--;
        }

        head = cur->next;


        cur->next = nullptr;

        return head;
        
        
    }
};