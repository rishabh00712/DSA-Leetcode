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
        int count=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        if(count<2) return true;
        bool isOdd=false;
        if(count%2!=0) isOdd=true;

        ListNode* pre;
        // find middle 
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        if(isOdd){
            pre->next=nullptr;
        }

        //reverse
        pre=nullptr;
        ListNode* node=slow;
        ListNode* next=slow->next;
        while(node){
            node->next=pre;
            pre=node;
            node=next;
            if(!next) {
                break;
            }
            next=next->next;
        }

        // compare
        ListNode* firstHalf=head;
        ListNode* secondHalf=pre;
        while(firstHalf && secondHalf){
            if(firstHalf->val !=secondHalf->val) return false;
            
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        return true;
    }
};