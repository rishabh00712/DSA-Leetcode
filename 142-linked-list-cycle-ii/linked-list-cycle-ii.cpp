/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> storeList;
        ListNode* temp=head;
        while(temp){
            if(storeList.find(temp)!=storeList.end()){
                return temp;
            }
            storeList.insert(temp);
            temp=temp->next;
        }
        return nullptr;
    }
};