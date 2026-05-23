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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* curr_l1 = l1;
        ListNode* curr_l2 = l2;
        ListNode ans(0);
        ListNode* ans_curr = &ans;
        int carry = 0;

        while(curr_l2 || curr_l1 || carry > 0){
            int templ1 = 0;
            int templ2 = 0;
            if(curr_l1){
                templ1 = curr_l1->val;
            }
            if(curr_l2){
                templ2 = curr_l2->val;
            }
            int sum = templ1 + templ2 + carry;
            
            if(sum >= 10){
                carry = sum / 10;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            
            ans_curr->next = new ListNode(sum);
            ans_curr = ans_curr->next;
            if(curr_l1)curr_l1 = curr_l1->next;
            if(curr_l2)curr_l2 = curr_l2->next;

        }
        return ans.next;
    }
};
