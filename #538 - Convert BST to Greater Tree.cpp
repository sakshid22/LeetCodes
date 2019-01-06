//538

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
    
private:
    int cur_sum =0;
public:
    void traverse(TreeNode* root) {
        
            if(!root) return;
            if(root -> right) traverse(root -> right);
            
            root -> val = (cur_sum += root -> val);
            if(root -> left) traverse (root -> left );
        }    
        
    TreeNode* convertBST( TreeNode* root)
       {
        traverse(root);
        return root;
       }
};