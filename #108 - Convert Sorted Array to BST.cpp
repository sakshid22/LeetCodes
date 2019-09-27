// #108 - Convery Sorted Array to BST

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
    
TreeNode* Convert (const vector<int> &nums, int lo, int hi)
{
    if(lo>hi) 
            return NULL;
        int mid = (lo+hi)/2;
        TreeNode *t = new TreeNode(nums[mid]);
        
        t->left = Convert(nums, lo, mid -1);
        t->right = Convert(nums, mid+1, hi);
        return t;
}
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return Convert(nums, 0, nums.size()-1);       
    }
    

};