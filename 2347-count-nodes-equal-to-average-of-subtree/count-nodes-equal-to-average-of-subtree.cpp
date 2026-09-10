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
    vector<int> sumOfAvg(TreeNode* root,int& total){
        if(!root) return {0,0};
        auto left=sumOfAvg(root->left,total);
        auto right=sumOfAvg(root->right,total);
        int n = 1+left[1]+right[1];
        int sum = root->val+left[0]+right[0];
        if(sum/n==root->val){
            total++;
        }
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int total=0;
        sumOfAvg(root,total);
        return total;
    }
};