/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;
        while (curr != NULL) {
            // valid child node
            if (curr->child != NULL) {
                Node* nextPtr = curr->next;

                // 1. flatten the all child node
                curr->next = flatten(
                    curr->child); // flatten each level and join to curr->next
                curr->next->prev = curr;
                curr->child = NULL;

                // 2. find tail of the flatten list
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                // 3. attach with next ptr
                if (nextPtr != NULL) {
                    curr->next = nextPtr;
                    nextPtr->prev = curr;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};