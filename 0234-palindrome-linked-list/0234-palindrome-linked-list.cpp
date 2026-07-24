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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        ListNode* prev=NULL;
        while(fast != NULL && fast->next!=NULL){
            ListNode* temp=slow->next;
            fast=fast->next->next;
            slow->next=prev;
            prev=slow;
            slow=temp;

        }
        if (fast != NULL)
            slow = slow->next;

        while(prev!=NULL &&  slow!=NULL){
            if(prev->val!=slow->val){
                return 0;
            }
            prev=prev->next;
            slow=slow->next;
        }
        return 1;
    }
};