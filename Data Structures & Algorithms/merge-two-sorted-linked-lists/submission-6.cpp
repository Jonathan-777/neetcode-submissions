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
    struct minHeapHelper{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<ListNode*, vector<ListNode*>, minHeapHelper> pq;

        while(list1){
            pq.push(list1);
            list1 = list1->next;
        }
        while(list2){
            pq.push(list2);
            list2 = list2->next;
        }
        ListNode* head = new ListNode(0);
        ListNode* traverse = head;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            traverse->next = temp;
            traverse = traverse->next;
        }
        traverse->next = nullptr;
        return head->next;
    }
};
