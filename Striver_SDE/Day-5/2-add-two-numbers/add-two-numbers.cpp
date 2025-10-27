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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify logic
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Loop while there is something to process
        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            current->next = newNode;  // Create node with digit
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            current->next = newNode;
        }

        return dummyHead->next;  // skip dummy node
    }
};









/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify logic
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Loop while there is something to process
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);  // Create node with digit
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummyHead->next;  // skip dummy node
    }

*/