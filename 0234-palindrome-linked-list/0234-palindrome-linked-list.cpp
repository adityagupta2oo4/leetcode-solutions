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
        
        ListNode* it = head;

        if(head->next == nullptr) return true;
        vector<int> arr;
        
        int right = -1;
        while(it){
            arr.push_back(it->val);
            right++;
            it = it->next;
        }
        cout<<right;

        int left = 0;

        while(left < right){
            cout<<arr[left];
            cout<<arr[right];
            if(arr[left] != arr[right]) return false;
            left++;
            right--;

        }

        return true;



    }
};