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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> list;
         ListNode* temp = head;
        int pre=head->val;
        int ind=1;
        while(temp->next!=nullptr){
            int val=temp->val;
            int next=temp->next->val;
            if(pre>val && next>val){
                list.push_back(ind);
            }
            if(pre<val && next<val){
                list.push_back(ind);
            }
            pre=val;
            ind++;
            temp=temp->next;
        }
        for(auto n : list){
            cout<<n<<endl;
        }
        int n=list.size();
        if(n<2) return {-1,-1};
        int maxi=list[n-1]-list[0];
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            mini=min(mini,(list[i]-list[i-1]));
        }
        return {mini,maxi};
    }
};