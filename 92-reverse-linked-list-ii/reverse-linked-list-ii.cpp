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
    ListNode* reverseLL(ListNode* head, ListNode* tail) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = head->next;

        while (curr != tail) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) {
            return head;
        }
        ListNode* temp = head;
        ListNode* st = NULL;
        ListNode* end = NULL;
        ListNode* leftBefore = NULL;
        ListNode* rightAfter = NULL;

        // Move temp to the left position
        for (int i = 1; i < left; i++) {
            leftBefore = temp;
            temp = temp->next;
        }

        st = temp;

        // Move temp to the right position
        for (int i = left; i < right; i++) {
            temp = temp->next;
        }

        end = temp;
        if (end->next != NULL) {
            rightAfter = end->next;
        }

        ListNode* newHead = st;
        ListNode* tail = rightAfter;

        ListNode* reversell = reverseLL(newHead, tail);
        if (leftBefore == NULL && rightAfter == NULL) {
            return reversell;
        }
        if (leftBefore == NULL) {
            head = reversell;
        } else {
            leftBefore->next = reversell;
        }

        st->next = rightAfter;

        return head;
    }
};