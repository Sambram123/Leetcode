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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        ListNode* before=nullptr;
        int i=1;
        while(i<left){
            before=temp;
            temp=temp->next;
            i++;
        }

        ListNode* curr=temp;
        ListNode* prev=nullptr;
        int times=right-left+1;
        while(times--){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        temp->next=curr;
        if(before){
        before->next=prev;
        return head;
        }
        return prev;

    }
};