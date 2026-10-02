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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // Another approach using recursion

        // base case
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // here two case 
        // 1. head1->value <= head2->value;
        // 2. head1->value >= head2->value;

        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next,head2);
            return head1;
        }else{
            head2->next = mergeTwoLists(head1,head2->next);
            return head2;
        }

    }
};