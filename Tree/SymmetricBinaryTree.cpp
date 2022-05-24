//https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr and root2 == nullptr) return 1;
    if (!root1 or !root2 or root1->val != root2->val) return 0;
    return solve(root1->left, root2->right) && solve(root1->right, root2->left);
}
int Solution::isSymmetric(TreeNode* A) {
    return solve(A, A);
}
