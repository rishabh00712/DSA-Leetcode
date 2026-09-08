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
    vector<int> postorderTraversal(TreeNode* root) {
        set<TreeNode*> myset;
        stack<TreeNode*> mystack;
        vector<int> vec;
        mystack.push(root);
        while(!mystack.empty()){
            
            root=mystack.top();
            if(root==nullptr)  {
                mystack.pop();
                continue;
            }
            if(myset.find(root)!=myset.end()){
                vec.push_back(root->val);
                mystack.pop();
                continue;
            }
            myset.insert(root);
            
            cout<<root->val;
            mystack.push(root->right);
            mystack.push(root->left);
        }
        return vec;
    }
};