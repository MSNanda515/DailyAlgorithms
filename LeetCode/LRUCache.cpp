// Uses a linked list (doubly linked) to reorder the items in constant time
// uses a map to determine whether items present in cache and position of item in linked list in const time
class LRUCache {
    class Node {
        public:
        int key = 0;
        int val = 0;
        Node* next = NULL, *prev = NULL;
        Node(int k, int v, Node* n, Node* p) {
            key = k; val = v; next = n; prev = p;
        }
    };

    unordered_map<int, Node*> bag;
    Node* head = NULL, *tail = NULL;
    int cap = 0;
    int cur = 0;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (bag.find(key) != bag.end()) {
            putNodeAtEnd(bag[key]);
            return bag[key]->val;
        }
        return -1;
    }

    void putNodeAtEnd(Node* node) {
        if (node->next == NULL && node->prev == NULL) {
            return;
        }
        if (node->prev == NULL) {
            // change head
            head = node->next;
            head->prev = NULL;
            tail->next = node;
            node->prev = tail;
            tail = node;
            node->next = NULL;
        } else if (node->next == NULL) {
            // already at tail
            return;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail->next = node;
            node->prev = tail;
            tail = node;
            node->next = NULL;
        }
    }

    void insertNewNodeAtEnd(Node* node) {
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            node->next = NULL;
        }
    }

    void printList() {
        Node* ptr = head;
        while (ptr != NULL) {
            printf("(%d: %d) -> ", ptr->key, ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }

    void evictFirstNode() {
        if (head == NULL) {
            return;
        }
        Node* node = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        bag.erase(node->key);
        delete(node);
    }

    void put(int key, int value) {
        if (bag.find(key) != bag.end()) {
            // key found; rearrange the list to put this node at end
            putNodeAtEnd(bag[key]);
            bag[key]->val = value;
        } else {
            Node* node = new Node(key, value, NULL, NULL);
            insertNewNodeAtEnd(node);
            bag[key] = node;
            if (cap >= cur+1) {
                cur += 1;
            } else {
                evictFirstNode();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
