//https://www.interviewbit.com/problems/identical-binary-trees/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode *A, TreeNode *B) {
    if (A == nullptr and B == nullptr) return 1;
    if (!A or !B or A->val != B->val) return 0;
    return solve(A->left, B->left) && solve(A->right, B->right);
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return solve(A, B);
}
