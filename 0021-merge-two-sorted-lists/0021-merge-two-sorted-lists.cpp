class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* mover1 = list1;
        ListNode* mover2 = list2;

        ListNode* head = new ListNode();
        ListNode* prev = head;

        while (mover1 && mover2) {
            if (mover1->val <= mover2->val) {
                prev->next = new ListNode(mover1->val);
                mover1 = mover1->next;
            } else {
                prev->next = new ListNode(mover2->val);
                mover2 = mover2->next;
            }
            prev = prev->next;
        }

        while (mover1) {
            prev->next = new ListNode(mover1->val);
            prev = prev->next;
            mover1 = mover1->next;
        }

        while (mover2) {
            prev->next = new ListNode(mover2->val);
            prev = prev->next;
            mover2 = mover2->next;
        }

        return head->next;
    }
};