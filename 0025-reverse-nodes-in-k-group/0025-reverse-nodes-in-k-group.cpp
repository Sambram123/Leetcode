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
    void reverse(ListNode* left,int k){
        ListNode* curr=left;
        ListNode* prev=nullptr;
        while(k--){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left=head;
        ListNode* prevLeft=nullptr;
        ListNode* right;
        ListNode* res=nullptr;

        while(true){
            right=left;
            for(int i=0;i<k-1;i++){
                if(right==nullptr) break;
                right=right->next;
            }
            if(right){
                ListNode* nextLeft=right->next;
                reverse(left,k);

                if(prevLeft)
                    prevLeft->next=right;
                prevLeft=left;
                left=nextLeft;

                if(res==nullptr)
                    res=right;
            }
            else{
                if(prevLeft)
                    prevLeft->next=left;

                if(res==nullptr)
                    res=left;

                break;
            }
        }
        return res;
    }
};