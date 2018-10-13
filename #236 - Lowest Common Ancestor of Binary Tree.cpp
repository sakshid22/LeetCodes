//236

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        if (root == NULL || !p || !q)   return NULL;
        if (root == p || root == q)     return root;
        TreeNode *l = lowestCommonAncestor(root->left, p , q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l && r)  return root;
        return l?l:r; // Think deeper for this statement - If l has some value it will print l otherwise print r, bsaically initialy l is checking a true value
    }
};