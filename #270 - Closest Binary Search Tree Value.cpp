//270

public class Solution
{
	public int closestvalue(TreeNode root, double target)
	{
	int closest = root.val;
	double min= DOUBLE.MAX_VALUE;
		while(root!=NULL)
		{
		if(Math.abs(root.val_target)< min)
			{
			min=Math.abs(root.val-target);
			closest=root.val;
			}	
		if(target<root.val)
			root=root.left;
		else if(target > root.val)
			root=root.right;
		else
			return root.val;
		}
	}
	return closest;
}