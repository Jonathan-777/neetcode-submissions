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
        ListNode* list1_curr = list1;
        ListNode* list2_curr = list2;
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;


        while( list1_curr || list2_curr){
            if(list1_curr && list2_curr){
                if(list1_curr->val <= list2_curr->val){
                    temp->next = new ListNode((*list1_curr).val);
                    list1_curr = list1_curr->next;
                }else{
                    temp->next = new ListNode((*list2_curr).val);
                    list2_curr = list2_curr->next;
                }
            }else if(list1_curr && !list2_curr){
                temp->next = new ListNode((*list1_curr).val);
                list1_curr = list1_curr->next;

            }else{
                temp->next = new ListNode((*list2_curr).val);
                list2_curr = list2_curr->next;
            }
            temp = temp->next;


        }

        temp->next = nullptr;
        return newHead->next;
        
    }
};
