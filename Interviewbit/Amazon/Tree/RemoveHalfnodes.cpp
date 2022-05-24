//https://www.interviewbit.com/problems/remove-half-nodes/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    function <TreeNode *(TreeNode *)> go = [&](TreeNode * root) {
        if (root == nullptr) return (TreeNode *)nullptr;
        TreeNode *left = go(root->left);
        TreeNode *right = go(root->right);
        root->left = left;
        root->right = right;
        if (left and !right) {
            return left;
        }
        if (!left and right)
            return right;
        return root;
    };
    return go(A);
}
