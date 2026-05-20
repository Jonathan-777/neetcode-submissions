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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp = head;

        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }
        temp = head;
        

        int l = 1; 
        int r = v.size()-1;
        bool turnL = false;

        while(l <= r){
            if(turnL){
                temp->next = v[l++];
                temp = temp->next;
                turnL=false;
            }else if( !turnL){
                temp->next = v[r--];
                temp = temp->next;
                turnL = true;
            }

        }
        temp->next = nullptr;
        
    }
};
