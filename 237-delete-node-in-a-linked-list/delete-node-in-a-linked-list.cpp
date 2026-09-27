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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* next = curr->next;
        ListNode* nextN = next->next;
        int holdNext = next->val;
        curr->next=nextN;
        curr->val = holdNext;
        next = NULL;

    }
};