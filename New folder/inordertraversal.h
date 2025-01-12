#include <vector>
typedef  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;

    void inorderHelper(TreeNode * root, std::vector<int> & nums)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            nums.push_back(root->val);
            return;
        }
        inorderHelper(root->left, nums);
        nums.push_back(root->val);
        inorderHelper(root->right, nums);

    }

std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> nums;
        inorderHelper(root, nums);
        return nums;
    }