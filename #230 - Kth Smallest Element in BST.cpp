//230 
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
    int kthSmallest(TreeNode* root, int k) {
    
        int count = countNodes(root->left);
        if(k==count+1)             // if the no. of terms on left is one less thab k-> the current term is the answer
            return root->val;
        
        //the kth element lies in the left side of the tree
        if(k<=count)    
            return kthSmallest(root->left, k);
        // kth smallest is on the right hand side
        else 
            //if(k > count +1)
            return kthSmallest(root->right, k-1-count);
    }
    inline int countNodes(TreeNode *n)
    {
        return n == NULL ? 0:(1+ countNodes(n->left) + countNodes(n->right));
        
    }
};