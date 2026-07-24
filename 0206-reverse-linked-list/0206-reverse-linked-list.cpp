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
    ListNode* reverseList(ListNode* head) {
        
        // getting to the last

        ListNode* last = head;
        if(last == nullptr){
            return head;
        }

        vector<int> arr;

        while(last){
            arr.push_back(last->val);
            last = last->next;
        }

        last = head;
        int i = arr.size()-1;

        while(last){
            last->val = arr[i];
            i--;
            last = last->next;
        }



        return head;
    }
};