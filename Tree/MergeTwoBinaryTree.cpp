//https://www.interviewbit.com/problems/merge-two-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if (A == nullptr) return B;
    if (B == nullptr) return A;
    function<void(TreeNode *, TreeNode *)> go = [&](TreeNode * root1, TreeNode * root2) {
        if (!root1 and !root2) return;
        root1->val += root2->val;
        if (!root1->left and root2->left) {
            root1->left = root2->left;
            root2->left = nullptr;
        }
        if (!root1->right and root2->right) {
            root1->right = root2->right;
            root2->right = nullptr;
        }
        if (root1->left and root2->left) {
            go(root1->left, root2->left);
        }
        if (root1->right and root2->right) {
            go(root1->right, root2->right);
        }
    };

    go(A, B);
    return A;
}
