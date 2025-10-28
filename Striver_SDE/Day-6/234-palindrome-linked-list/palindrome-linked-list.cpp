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
private:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    

public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        } // Found Middle

        ListNode *newHead = reverse(slow->next); // Reversing
        // Comparing
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL) {
            if(first->val != second->val) {
                reverse(newHead); // As we meddeling with the original array
                return false;}
            first = first->next;
            second = second->next;
        }
        // Reverse again to get original LL if it's false    _^_
        // If it's true then the about reverse won't get executed 
        reverse(newHead);

        return true;
    }
};


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         stack<int> st;
//         ListNode* temp = head;

//         while(temp != NULL) {
//             st.push(temp->val);
//             temp = temp->next;
//         }
//         temp = head;
//         while(temp!=NULL) {
//             if(temp->val != st.top()) return false;
//             st.pop();
//             temp = temp->next;
//         }
//         return true;


//     }
// };