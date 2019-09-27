#501 - Find Mode in BST.cpp

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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        int maxnum = 0;
        unordered_map <int,int> map;
        preorder(root, maxnum, map);
        for(auto entry: map)
        {
            if(entry.second == maxnum)
                res.push_back(entry.first);
        }
      return res;
        
    }
    
    void preorder(TreeNode* root, int& maxnum, unordered_map<int, int> &map)
    {
        if(!root) return;
        maxnum = max(maxnum, ++map[root->val]);
        preorder(root->left, maxnum, map);
        preorder(root->right, maxnum, map);
    }
    
    
};