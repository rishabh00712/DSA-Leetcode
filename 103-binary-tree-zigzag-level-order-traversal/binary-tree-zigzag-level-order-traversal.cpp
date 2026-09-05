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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> vec;
        if(!root) return vec;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        int ind=0;
        while(!myqueue.empty()){
            int size=myqueue.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* topNode=myqueue.front();
                myqueue.pop();
                temp.push_back(topNode->val);
                if(topNode->left){
                    myqueue.push(topNode->left);
                }
                if(topNode->right){
                    myqueue.push(topNode->right);
                }
            }
            if(ind%2){
                reverse(temp.begin(),temp.end());
            }
            vec.push_back(temp);
            ind++;
        }
        return vec;
    }
};