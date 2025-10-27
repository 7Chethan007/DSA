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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node that points to head
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Step 2: Move fast ahead by n+1 steps
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Step 3: Move fast to the end, maintaining the gap
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Step 4: Remove the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;  // free memory (optional in LeetCode)
        
        // Step 5: Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;  // free dummy node
        return newHead;
    }
};