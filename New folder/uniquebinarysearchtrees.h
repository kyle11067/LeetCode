#include <vector>
// #include <mem.h>
typedef  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;


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

int numTrees(int n) {
    if (n == 1) return 1;

    std::vector<int> used;
    for (int i = 1; i <= n; i++)
        used.push_back(i);        
    int table[n + 1];
    // memset(table, -1, sizeof(int) * (n + 1));
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= n; i ++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += (table[j] * table[i - 1 - j]);
        }
        table[i] = sum;
    }
    return table[n];


}