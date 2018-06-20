/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
     
        if(root==NULL)
            return 0;
        else if (root->left == 0 && root->right ==0 )
            return 1;
        else if (root->left ==0 )
            return 1+maxDepth(root->right);
        else if (root ->right ==0 )
            return 1+maxDepth ( root->left);
        else
        {
            int a=1+maxDepth(root->left);
            int b=1+maxDepth(root->right);
            return max(a,b);
        }
    }
};