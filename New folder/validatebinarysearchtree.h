typedef  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;

bool isValid(TreeNode * root, long lower, long higher)
{
  if (root == NULL)
      return true;
  if (root->val <= lower || root->val >= higher)
    return false;  
  if (root->left == NULL && root->right == NULL)
    return true;
  if ( (root->left != NULL && root->left->val >= root->val) || (root->right != NULL && root->right->val <= root->val) )
  {
      return false;
  }

  
  return (isValid(root->right, (root->val) > lower ? root->val: lower, higher) && isValid(root->left, lower, root->val< higher ? root->val : higher));

}

bool isValidBST(TreeNode* root) {
        
        return isValid(root, 0x8000000000000000, 0x7fffffffffffffff);

    
}