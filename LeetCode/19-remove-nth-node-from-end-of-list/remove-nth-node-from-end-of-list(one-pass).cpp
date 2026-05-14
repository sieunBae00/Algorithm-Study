``` cpp
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
        ListNode* front = head;
        ListNode* back = head;
        
        for(int i=0; i<n; i++){
            front = front->next; // front 먼저 n칸 앞으로 보내기
        }
        
        // 예외 케이스: head 노드가 지워지는 경우
        if(front == nullptr){ // front 가 n 칸 갔을 때 이미 nullptr 라면, head 노드가 지워진다.
            head = head->next;
            return head; 
        }

        while(front->next != nullptr){ // front-back 간격을 n으로 유지
            front = front->next;
            back = back->next;
        }
        
        back->next = back->next->next; // 뒤에서 n번쨰 노드 삭제

        return head;
    }
};
```
