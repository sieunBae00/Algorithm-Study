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
        ListNode* curr = head;
        int cnt = 1;

        // first pass: 전체 길이 알아내기
        while(curr->next != nullptr){
            curr = curr->next;
            cnt++;
        }

        //예외 케이스: head 노드가 지워지는 경우
        if(cnt == n){
            head = head->next;
            return head;
        }

        curr = head;
        // second pass: 뒤에서 n번째 노드 찾기
        for(int i=0; i < cnt-n-1; i++){
            curr = curr->next; // 뒤에서 n-1 번째 노드
        }

        curr->next = curr->next->next; // n-1번째 노드를 n+1번째 노드에 연결
        
        return head;
    }
};