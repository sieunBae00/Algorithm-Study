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
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int sum, quo, rem, carry(0);

        while(l1 != nullptr || l2 != nullptr || carry > 0){
            // sum 값 세팅
            sum = 0;
            if(l1 == nullptr && l2 != nullptr) {
                sum = l2->val;
                l2 = l2->next;
            }
            else if(l2 == nullptr && l1 != nullptr) {
                sum = l1->val;
                l1 = l1->next;
            }
            else if(l1 != nullptr && l2 != nullptr){
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(carry == 1) sum += 1;
            
            quo = sum / 10; // 몫
            rem = sum % 10; // 나머지, 0~9 사이 숫자

            curr->next = new ListNode(rem); // 새 노드 생성 및 연결
            curr = curr->next; // 포인터 한 칸 이동
            
            if(quo > 0) carry = 1; // 올림수
            else carry = 0;
        }

        return dummy->next;
    }
};