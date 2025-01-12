#include <vector>

typedef  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;


void insertNode(TreeNode * root, int val)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (val < root->val)
        {
            root->left = new TreeNode(val);
        } else if (val > root->val)
        {
            root->right = new TreeNode(val);
        }
        return;
    }
    if (val < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new TreeNode(val);
            return;
        }else
        {
            insertNode(root->left,val);
        }
    } else if (val > root->val)
    {
        if (root->right == NULL)
        {
            root->right = new TreeNode(val);
            return;
        }else
        {
            insertNode(root->right,val);
        }
    }
}

std::vector<TreeNode*> generator(std::vector<int> & comb)
{
    if (comb.size() == 0)
    {
        return {NULL};
    }
    if (comb.size() == 1)
    {
        return {new TreeNode(comb.at(0))};
    }

    std::vector<TreeNode * > trees;
    for (int i = 0; i < comb.size(); i ++)
    {
        std::vector<int> left(comb.begin(),comb.begin() + i);
        std::vector<int> right(comb.begin() + 1 + i, comb.end());
        std::vector<TreeNode * > leftSubTree = generator(left);
        std::vector<TreeNode * > rightSubTree = generator(right);
        for (TreeNode * l: leftSubTree)
        {
            for (TreeNode * r: rightSubTree)
            {
                TreeNode * root = new TreeNode(comb.at(i));
                root->left = l;
                root->right = r;
                trees.push_back(root);
            }
        }
    }
    return trees;

}

  std::vector<TreeNode*> generateTrees(int n) {
        std::vector<int> used;
        for (int i = 1; i <= n; i++)
            used.push_back(i);

        return generator(used);


    }