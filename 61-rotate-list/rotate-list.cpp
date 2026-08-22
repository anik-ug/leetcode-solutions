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
        if(!head || head->next==nullptr ||  k==0){
            return head;
        }
        ListNode* curr = head;
        int size=1;
        while(curr->next!=nullptr){ 
            size++; 
            curr=curr->next; 
        } 
        k%=size;
        curr->next = head; 
        int step = size-k;
        ListNode* tail = head;
        while(--step){
            tail=tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};