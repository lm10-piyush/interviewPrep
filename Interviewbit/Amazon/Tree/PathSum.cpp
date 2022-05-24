//https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode *root, long long sum, int B) {
    if (root == nullptr) return 0;
    long long curr = sum + root->val;
    if (!root->left and !root->right) {
        if (curr == B) return 1;
    }
    return solve(root->left, curr, B) || solve(root->right, curr, B);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    return solve(A, 0, B);
}
