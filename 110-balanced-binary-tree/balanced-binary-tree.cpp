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
    int check(TreeNode* root,bool& t){
        if(!root) return 0;
        int left=1+check(root->left,t);
        int right=1+check(root->right,t); 
        if(left!=right && left+1!=right && right+1!=left){
            t=false;
        }
        if(!t) return 0;
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool t=true;
        check(root,t);
        return t;
    }
};