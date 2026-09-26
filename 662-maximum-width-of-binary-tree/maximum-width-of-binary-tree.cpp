/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> store;
        store.push({root,0});
        long long ans=0;
        while(!store.empty()){
            int size=store.size();
            long long left=INT_MAX,right=INT_MIN;
            for(int i=0;i<size;i++){
                auto top=store.front();
                store.pop();
                long long val=top.second;
                left=min(left,val);
                right=max(right,val);
                TreeNode* node=top.first;
                if(node->left){
                    store.push({node->left,2*(val-left)+1});
                }
                if(node->right){
                    store.push({node->right,2*(val-left)+2});
                }
            }
            ans=max(ans,right-left+1);
        }
        return (int)ans;
    }
};


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int findASize(deque<TreeNode*>& que){
//         deque<TreeNode*> q=que;
//         //cout<<"hi"<<endl;
//         int size=q.size();
//         int i=1;
//         while(!q.empty()){
//             if(q.front()!=nullptr) break;
//             i++;
//             q.pop_front();
//         }
//         if(i==0) return 0;
//         int n=size;
//         while(!q.empty()){
//             if(q.back()!=nullptr) break;
//             n--;
//             q.pop_back();
//         }
//         //cout<<i<<" "<<n<<endl;
//         return (n-i+1);
//     }
//     int widthOfBinaryTree(TreeNode* root) {
//         deque<TreeNode*> storeQ;
//         storeQ.push_back(root);
//         int ans=0;
//         while(!storeQ.empty()){
//             int actualSize=findASize(storeQ);
//             int size=storeQ.size();
//             ans=max(ans,actualSize);
//             if(actualSize==0) break;
//             for(int i=0;i<size;i++){
//                 auto top=storeQ.front();
//                 storeQ.pop_front();
//                 if(!top){
//                     storeQ.push_back(nullptr);
//                     storeQ.push_back(nullptr);
//                     continue;
//                 }
//                 storeQ.push_back(top->left);
//                 storeQ.push_back(top->right);
//             }
//         }
//         return ans;
//     }
// };