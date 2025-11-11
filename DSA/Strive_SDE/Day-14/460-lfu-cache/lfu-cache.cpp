#include <unordered_map>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key, value, cnt;
        Node *prev, *next;
        Node(int k, int v)
            : key(k), value(v), cnt(1), prev(nullptr), next(nullptr) {}
    };

    struct List {
        int size;
        Node *head, *tail; // dummy sentinels
        List() : size(0) {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }
        ~List() {
            Node* cur = head;
            while (cur) {
                Node* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            ++size;
        }
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            --size;
        }
    };

    int cap;                           // maximum capacity
    int curSize;                       // current number of items
    int minFreq;                       // minimum frequency present
    unordered_map<int, Node*> keyNode; // key -> node
    unordered_map<int, List*>
        freqListMap; // freq -> list of nodes with this freq

    // Move a node from its current freq list to (freq+1) list
    void increaseFreq(Node* node) {
        int oldFreq = node->cnt;
        List* oldList = freqListMap[oldFreq];
        oldList->removeNode(node);

        // if this node was the only one in the minFreq list, bump minFreq
        if (oldFreq == minFreq && oldList->size == 0) {
            ++minFreq;
        }

        node->cnt = oldFreq + 1;
        // ensure next frequency list exists
        if (freqListMap.find(node->cnt) == freqListMap.end()) {
            freqListMap[node->cnt] = new List();
        }
        freqListMap[node->cnt]->addFront(node);
        // keyNode mapping remains valid (pointer unchanged)
    }

public:
    LFUCache(int capacity) : cap(capacity), curSize(0), minFreq(0) {}

    ~LFUCache() {
        // Free all lists (which also free their nodes and sentinels)
        for (auto& kv : freqListMap) {
            delete kv.second;
        }
        // keyNode holds raw pointers to nodes already deleted by lists
        // so we don't delete nodes here again.
    }

    int get(int key) {
        if (cap == 0)
            return -1;
        auto it = keyNode.find(key);
        if (it == keyNode.end())
            return -1;

        Node* node = it->second;
        increaseFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        auto it = keyNode.find(key);
        if (it != keyNode.end()) {
            // Update value and bump frequency
            Node* node = it->second;
            node->value = value;
            increaseFreq(node);
            return;
        }

        // Evict if at capacity
        if (curSize == cap) {
            List* list = freqListMap[minFreq];
            Node* toRemove = list->tail->prev; // LRU within the min frequency
            keyNode.erase(toRemove->key);
            list->removeNode(toRemove);
            delete toRemove;
            --curSize;
        }

        // Insert new node with freq = 1
        Node* node = new Node(key, value);
        minFreq = 1;
        if (freqListMap.find(minFreq) == freqListMap.end()) {
            freqListMap[minFreq] = new List();
        }
        freqListMap[minFreq]->addFront(node);
        keyNode[key] = node;
        ++curSize;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */