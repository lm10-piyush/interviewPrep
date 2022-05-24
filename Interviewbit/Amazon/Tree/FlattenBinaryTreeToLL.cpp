//https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    function<void(TreeNode *)> dfs = [&](TreeNode * root) {
        if (root == nullptr) return;
        dfs(root->left);
        dfs(root->right);
        if (root->left != nullptr) {
            TreeNode *curr = root->left;
            while (curr->right != nullptr) {
                curr = curr->right;
            }
            curr->right = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
    };
    dfs(A);
    return A;
}
