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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        vector<int> arr;

        ListNode* mover = list1;


        while(mover){
            arr.push_back(mover->val);
            mover = mover->next;
        }
        mover = list2;
        while(mover){
            arr.push_back(mover->val);
            mover = mover->next;
        }

        if(arr.size() == 0) return list1;

        sort(arr.begin(), arr.end());

        ListNode* head = new ListNode(arr[0]);   // first node
        ListNode* current = head;

        for (int i = 1; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]); // link new node
            current = current->next;              // move forward
        }

        return head;


    }
};