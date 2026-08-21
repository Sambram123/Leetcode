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
        if(head==nullptr) return nullptr;
        ListNode* last=head;
        int n=1;

        while(last->next!=nullptr){
            n++;
            last=last->next;
        }

        k=k%n;
        if(k==0) return head;

        ListNode* newHead=head;
        ListNode* newLast=head;

        for(int i=1;i<n-k;i++){
            newLast=newLast->next;
        }

        newHead=newLast->next;
        last->next=head;
        newLast->next=nullptr;

        return newHead;
    }
};