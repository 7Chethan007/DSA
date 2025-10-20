/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        // 1. Setup Dummy Node
        ListNode dummy(0);
        dummy.next = head;
        
        // Find the node BEFORE the reversal starts (L-1 position).
        // We use leftPrev to anchor the entire segment.
        ListNode* leftPrev = &dummy; 
        for (int i = 0; i < left - 1; ++i) {
            leftPrev = leftPrev->next;
        }

        // 'current_left_node' is the first node of the segment (the fixed tail after reversal).
        ListNode* current_left_node = leftPrev->next;
        
        // Pointers for the iterative reversal within the segment
        ListNode* prev = nullptr; // Initialize previous node for the reversal
        ListNode* curr = current_left_node; // Start at the left node
        
        // We will stop when we reach the node *after* the right position
        int count = right - left + 1;

        // 2. Perform the reversal on the sub-segment [left, right]
        for (int i = 0; i < count; ++i) {
            ListNode* next_node = curr->next;
            
            // Reversal: Reverse the pointer
            curr->next = prev; 
            
            // Advance pointers
            prev = curr; 
            curr = next_node;
        }

        // At this point:
        // 'leftPrev' points to the node before L.
        // 'prev' points to the original R node (the new head).
        // 'current_left_node' points to the original L node (the new tail).
        // 'curr' points to the node after R.

        // 3. Reconnect the boundaries

        // a. Connect the new tail (original L node) to the segment after R (curr)
        current_left_node->next = curr;

        // b. Connect the anchor node (before L) to the new head (original R node, prev)
        leftPrev->next = prev;

        return dummy.next;
    }
};