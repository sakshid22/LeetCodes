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
    
    int res =0,i;
    int longestUnivaluePath(TreeNode* root) {
      
        if(root==NULL)
            return 0;
        post(root);
        return max(0,res-1);
    }
    
    int post(TreeNode *r)
    {
        int l=0, ri=0;
        if(r->left ==NULL && r->right == NULL)
            return 1;
        if(r->left)
             l=post(r->left);
        if(r->right)
            ri = post(r->right);
        if(l!= 0 && r->left->val != r->val)
            l=0;
        if(ri!=0 && r->right->val != r->val)
            ri =0;
        res = max (res, l+ri+1);
        return max (l,ri)+1;
    }
};