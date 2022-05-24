//https://www.interviewbit.com/problems/balanced-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
pair<int, int> solve(TreeNode *root) { //{Is subtree root ok?, height of current node}
    if (root == nullptr) return {1, 0};
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    int b = abs(left.second - right.second);
    int ok = (b <= 1) && left.first && right.first;
    return {ok, max(left.second, right.second) + 1};
}
int Solution::isBalanced(TreeNode* A) {
    return solve(A).first;
}
