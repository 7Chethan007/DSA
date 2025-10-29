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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL||k == 0) return head;
        // Calculate the length of the list.
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next != nullptr) {
            ++cnt;
            temp = temp->next;
        }
        // Connect the last node to the first node, converting it to a circular linked list.
        temp->next = head;
        // Iterate to cut the link of the last node and start a node of k%length of the list rotated list.
        k = k % cnt; //when k is more than length of list
        int end = cnt - k; //to get end of the list 

        while(end--) temp = temp->next;
        head = temp->next;
        temp->next = NULL;
            
        return head;
    }
};