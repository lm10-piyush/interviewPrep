//https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode *root) {
    if (root == nullptr) return 0;
    if (!root->left and !root->right) return 1;
    int mn = 1e9;
    if (root->left) mn = min(solve(root->left), mn);
    if (root->right) mn = min(solve(root->right), mn);
    return mn + 1;
}

int Solution::minDepth(TreeNode* A) {
    return solve(A);
}
/*
25 9 11 10 7 5 -1 12 -1 -1 8 1 -1 6 -1 -1 -1 -1 2 -1 -1 3 4 -1 -1 -1

5 1 2 3 -1 -1
*/