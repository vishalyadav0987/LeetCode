class LRUCache {
public:
    // here we using doubly linklist for design catched
    // unorderd map for reterive LRU cache in o(1) complexity

    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            this->key = k;
            this->val = v;
            next = prev = NULL;
        }
    };

    // We define head and Tail with value -1 for removing handling NULL case
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;
    int limit;

    // Simple baatien that remember in future
    // that Node head -> next is MRU (Most recent used)
    // that Node tail -> prev is LRU (Least recent used)

    // helper function

    // head
    // ↓
    // [-1] ⇄ [-1]
    //         ↑
    //         tail

    void insertAtHeadNext(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    // head
    // ↓
    // [-1] ⇄ [2] ⇄ [-1]
    //          ↑     ↑
    //          ON    tail

    void deleteNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* ansNode = mpp[key];
        int ans = ansNode->val;
        // if jaise hi hum get karte hai toh woh value Most recent used value
        // ban jayegi delete that value and insert on head; delete or insert
        // isliye kyuki jaise hi ush value ko get karge woh value MRU ban jayegi
        mpp.erase(key);
        deleteNode(ansNode);

        insertAtHeadNext(ansNode);
        mpp[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        // 1st case if key same and value is different so, we remove that key
        // from both
        if (mpp.find(key) != mpp.end()) {
            Node* oldNode = mpp[key];
            deleteNode(oldNode);
            mpp.erase(key);
        }

        // 2nd if Limit reached, so remove LRU value
        if (mpp.size() == limit) {
            // delete LRU data
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // add new node
        Node* newNode = new Node(key, value);
        insertAtHeadNext(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */