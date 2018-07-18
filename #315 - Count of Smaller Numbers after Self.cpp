//315

class Solution {
public:
   
    struct Node{
        
        int val, smaller;
        Node *left, *right;
        Node(int value, int small)
        {
            left=right=NULL,
            val= value,
            smaller = small;
        }   
    };
    
    int insert(Node *&root,  int value)
    {
        if(root == NULL)
            return(root = new Node(value, 0)),0;
        if(value < root-> val)
            return root->smaller++ , insert(root->left, value);
        else
            return insert(root-> right, value)+ root->smaller + (value>root->val ? 1:0);
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
    Node *root = NULL;
        deque<int> ans;
            for(int i=nums.size()-1; i>=0; i--)
                ans.push_front(insert(root, nums[i]));
        return vector<int> (ans.begin(), ans.end());
    }
};