//https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::lca(TreeNode* A, int B, int C) {
    int found = 0, ans = -1;
    function<int(TreeNode *)> go = [&](TreeNode * root) {
        if (root == nullptr) return 0;
        int cnt = (root->val == B) + (root->val == C) + go(root->left) + go(root->right);
        if (!found and cnt == 2) {
            found = 1;
            ans = root->val;
        }
        return cnt;
    };
    go(A);

    return ans;
}
