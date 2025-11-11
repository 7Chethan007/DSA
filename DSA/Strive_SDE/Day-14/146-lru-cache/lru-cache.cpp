#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void detach(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void attachAfterHead(Node* n) {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
    }

    void moveToFront(Node* n) {
        detach(n);
        attachAfterHead(n);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            moveToFront(node);
            return;
        }

        if ((int)mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            detach(lru);
            delete lru;
        }

        Node* node = new Node(key, value);
        attachAfterHead(node);
        mp[key] = node;
    }
};
