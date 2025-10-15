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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap of (node value, node pointer)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> minHeap;

        // Push the head of each list into the heap
        for (auto node : lists) {
            if (node) {
                minHeap.push({node->val, node});
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            auto [val, node] = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                minHeap.push({node->next->val, node->next});
            }
        }

        return dummy.next;
    }
};