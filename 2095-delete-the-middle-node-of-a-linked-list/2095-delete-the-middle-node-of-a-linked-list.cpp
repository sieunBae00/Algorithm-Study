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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr) fast = fast->next;
        }

        ListNode* mid = slow->next;
        slow->next = mid->next;

        return dummy->next;
    }
};