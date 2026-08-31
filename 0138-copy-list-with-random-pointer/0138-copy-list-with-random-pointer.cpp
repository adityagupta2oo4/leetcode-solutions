/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        

        if(head == nullptr) return head;
       
       // interweaving  algo using constant space
       // A->COPY -> B -> COPY

       // making the copy 

       Node* cur = head;

       //just leaving the random and copying the rest

       while(cur){

        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
        cur = cur->next->next;
        
       }

       //now handling the random

       cur = head;

       while(cur){

        cur->next->random = (cur->random) ? cur->random->next : nullptr;
        cur = cur->next->next;

       }

       // now deleting the original

       cur = head;
       head = cur->next;

       while(cur){

        Node* copy = cur->next;

        // geting original

        cur->next = copy->next;

        if(copy->next){
            copy->next = copy->next->next;
        }
        cur = cur->next;

       }

       return head;

       

    }
};