class Solution {
public:
        ListNode* rotateRight(ListNode* head, int k) {
                if (head == nullptr || head->next == nullptr || k == 0) return head;

                // 1) Compute the length and get the tail node.
                ListNode* tail = head;
                int length = 1;
                while (tail->next != nullptr) {
                        ++length;
                        tail = tail->next;
                }

                // 2) Make the list circular by connecting tail to head.
                tail->next = head;

                // 3) Normalize k in case it's >= length.
                k = k % length;
                if (k == 0) {
                        tail->next = nullptr; // break the temporary circle
                        return head;
                }

                // 4) Find the new tail: it will be at position (length - k) from the start.
                int stepsToNewTail = length - k;
                ListNode* newTail = head;
                for (int i = 1; i < stepsToNewTail; ++i) {
                        newTail = newTail->next;
                }

                // 5) Set the new head and break the circle.
                ListNode* newHead = newTail->next;
                newTail->next = nullptr;

                return newHead;
        }
};