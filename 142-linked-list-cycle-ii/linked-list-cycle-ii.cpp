/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // here two question raise
        // 1. return where cycle start
        // 2. remove cycle find start of cycle then stCycle->prev = NULL

        // 1. detect cycle first;
        ListNode* slow=head;
        ListNode* fast=head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast){
                isCycle=true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;
        while(slow != fast){
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};