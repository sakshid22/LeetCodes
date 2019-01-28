//865

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
    
/*
    int res;
    TreeNode* node;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        res=0;
        searchPath(root,0);
        return node;
    }
        int searchPath(TreeNode* root, int deep)
        {
            if(root == NULL)    return deep;
            int l = searchPath(root->left, deep+1);
            int r = searchPath(root->right, deep+1);
                if(l==r)
                {
                    if(l>=res)
                    {
                        res=1;
                        node=root;
                    }
                }
            return max(l,r);
        }
        
*/int depth(TreeNode *root)
{
    return !root ? 0:max(depth(root->left), depth(root->right)) +1;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        int d = depth(root->left) - depth(root->right);
        return !d ? root:subtreeWithAllDeepest(d> 0 ? root->left: root->right);
    }
    };
