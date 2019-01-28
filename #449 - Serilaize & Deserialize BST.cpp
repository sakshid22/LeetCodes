//449

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serialize( TreeNode *root, vector <int> &val)
    {
        if(root == NULL) return;
        val.push_back(root->val);
        serialize(root->left, val);
        serialize(root->right, val);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
     vector <int> val;
        serialize(root,val);
        char *p = (char*)val.data();
        string str(p,val.size()*sizeof(int));
        return str;
    }

    
    TreeNode *deserializeSubtree(int *val, int l, int r)
    {
        if(l>r) return NULL;
        TreeNode *SubRoot = new TreeNode(val[l]);
        int i=l+1;
        while(i<=r && val[i]<val[l]) ++i;
        SubRoot ->left = deserializeSubtree(val, l+1, i-1);
        SubRoot -> right = deserializeSubtree(val, i, r);
        return SubRoot;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size()/sizeof(int);
        TreeNode *root = deserializeSubtree((int*)data.data(), 0, n-1);
        return root;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));