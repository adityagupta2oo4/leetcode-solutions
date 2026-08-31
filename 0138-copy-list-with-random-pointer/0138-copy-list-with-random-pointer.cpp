class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        // Step 1: Interweave copied nodes
        // A -> A' -> B -> B' -> C -> C'

        Node* cur = head;

        while (cur) {

            Node* copy = new Node(cur->val);

            copy->next = cur->next;
            cur->next = copy;

            cur = copy->next;   // IMPORTANT
        }


        // Step 2: Set random pointers

        cur = head;

        while (cur) {

            cur->next->random =
                (cur->random) ? cur->random->next : nullptr;

            cur = cur->next->next;
        }


        // Step 3: Separate original and copied lists

        cur = head;
        Node* newHead = head->next;

        while (cur) {

            Node* copy = cur->next;

            // Restore original list
            cur->next = copy->next;

            // Connect copied list
            if (copy->next) {
                copy->next = copy->next->next;
            }

            cur = cur->next;
        }

        return newHead;
    }
};