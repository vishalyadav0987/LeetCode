/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // here trick is we store all node in unorderd map
        // oldNode -> newNode
        unordered_map<Node*,Node*>mpp;
        mpp[head]=newHead;

        // Step:1 copy whole Link list
        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            mpp[oldTemp]=copyNode;
            newTemp->next = copyNode;

            newTemp=newTemp->next;
            oldTemp=oldTemp->next;
        }

        // step: 2 mock the random pointer
        // mpp structure<oldNode,newNode>
        // 7 -> 7
        // 13 -> 13
        // 11 -> 11
        // 10 -> 10
        // 1 -> 1
        // Special Point : newTemp->random=mpp[oldTemp]->random;
        oldTemp = head, newTemp = newHead;
        while(oldTemp != NULL){
            newTemp->random=mpp[oldTemp->random];
            newTemp=newTemp->next;
            oldTemp=oldTemp->next;
        }

        return newHead;
    }
};