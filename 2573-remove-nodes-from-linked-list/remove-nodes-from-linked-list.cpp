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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = reverseList(head);
        int maxValue = newHead->val;
        ListNode* curr = newHead;
        ListNode* next = curr->next;
        ListNode* temp = newHead;
        while (next != NULL) {
            if (maxValue <= next->val) {
                maxValue = next->val;
                next = next->next;
                temp = temp->next;
            } else {
                cout<< next->val;
               temp->next = next->next;
               next = temp->next;
            }
        }
        
        return reverseList(curr);
    }
};