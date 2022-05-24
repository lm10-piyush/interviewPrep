// https://www.interviewbit.com/problems/2sum-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    vector <int> inorder;
    function<void(TreeNode *)> dfs = [&](TreeNode * root) {
        if (root == nullptr) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    };
    dfs(A);
    int l = 0, r = (int)inorder.size() - 1;
    while (l < r) {
        int sum = inorder[l] + inorder[r];
        if (sum == B) return 1;
        if (sum < B) l++;
        else r--;
    }
    return 0;
}
