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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev_tail = dummy;


        auto reverse = [&](ListNode* og_start){
            
            ListNode* prev = nullptr;
            ListNode* curr = og_start;
            ListNode* nextNode = nullptr;
            for(int i = 0 ; i < k ; ++i){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            og_start->next = nextNode;
            return prev;
        };


        int counter = 0;
        bool first_iteration = true;

        while(curr){
            ListNode* temp_start = curr;
            while(curr && counter < k){
                counter++;
                curr = curr->next;
            }
            if(counter == k){

                ListNode* reversed_node = reverse(temp_start);
                if(first_iteration){
                    first_iteration = false;
                    dummy->next = reversed_node;
                }else{
                    prev_tail->next = reversed_node;
                    
                }
                prev_tail = temp_start;
                // curr = reversed_node->next;
                
            }else {
                // FIX 2 (Edge Case): If we have less than k nodes left, just attach them 
                // to the end of our finished list and break out of the loop.
                if (!first_iteration) {
                    prev_tail->next = temp_start;
                } else {
                    dummy->next = temp_start;
                }
                break;
            }
            counter = 0;
        }
        return dummy->next;
    }
};
