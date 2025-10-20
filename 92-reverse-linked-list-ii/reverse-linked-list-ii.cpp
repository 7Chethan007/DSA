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

        // 1. Create a dummy node to handle the case where the reversal starts at the head (left=1).
        ListNode dummy(0);
        dummy.next = head;
        
        // 'prev_left_node' will point to the node JUST BEFORE the 'left' position.
        // It remains fixed throughout the reversal.
        ListNode* prev_left_node = &dummy; 
        for (int i = 0; i < left - 1; ++i) {
            prev_left_node = prev_left_node->next;
        }

        // 'current_left_node' will be the first node of the segment to be reversed.
        // It remains fixed as the 'tail' of the reversed segment.
        ListNode* current_left_node = prev_left_node->next;

        // 2. Iteratively reverse the segment from 'left' to 'right'.
        // We need (right - left) reversal steps.
        ListNode* prev = current_left_node;
        ListNode* current = current_left_node->next; 

        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = current->next;
            
            // Reversal: Reverse the direction of 'current' node's pointer.
            current->next = prev; 
            
            // Move pointers one step forward
            prev = current; 
            current = next_node;
        }

        // 3. Reconnect the reversed segment to the rest of the list.

        // 'prev' is now the new head of the reversed segment (the original 'right' node).
        // Connect the node before the segment to the new head.
        prev_left_node->next = prev;

        // 'current_left_node' is now the tail of the reversed segment (the original 'left' node).
        // Connect the new tail to the node immediately following the 'right' position (which is 'current').
        current_left_node->next = current;

        // 4. Return the head of the modified list (which is dummy.next).
        return dummy.next;
    }
};