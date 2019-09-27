#107 Binary Tree Level Order Traversal II

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
   public Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        helper(root, 1);
        for(int i =map.keySet().size(); i>0; i--)
        {
            result.add(map.get(i));
        }
        return result;   
    }
    
    public void helper(TreeNode node, int level)
    {
        if(node !=null)
        {
            if (map.containsKey(level))
            {
                map.get(level).add(node.val);
            }
            else
            {
                List<Integer> list = new ArrayList <Integer>();
                list.add (node.val);
                map.put (level, list);
            }
            helper(node.left, level+1);
            helper(node.right, level+1);
        }
    }
}