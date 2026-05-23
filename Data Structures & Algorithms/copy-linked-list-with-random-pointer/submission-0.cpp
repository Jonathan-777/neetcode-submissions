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
        if(!head)return nullptr;
        Node* newHead = new Node(0);
        Node* curr = head;
        Node* new_curr = newHead;

        while(curr){
            new_curr->next = new Node(curr->val);
            new_curr = new_curr->next;
            new_curr->random = curr->random;
            
            curr->random = new_curr;
            curr = curr->next;
            
        }
        // new_curr->next = nullptr;

        new_curr = newHead->next;
        curr = head;

        while(new_curr){
           new_curr->random = (new_curr->random )? new_curr->random->random : nullptr;
            new_curr = new_curr->next;


        }
        

        return newHead->next;
    }
};
