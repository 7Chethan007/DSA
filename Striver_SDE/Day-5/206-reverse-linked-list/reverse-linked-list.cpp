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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while(head != nullptr) {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;




















        // see strivers notes for visual rep iterate for a list of 3 node Done and dusted
        // ListNode* newHead = nullptr;
        // while(head != nullptr) {
        //     ListNode* next = head->next;
        //     head->next = newHead;
        //     newHead = head;
        //     head = next;
        // }
        
        // return newHead;
    }
};