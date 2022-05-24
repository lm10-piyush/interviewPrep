//https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    function<TreeNode *(int, int)> dfs = [&](int l, int r) {
        if (l > r) return (TreeNode *)nullptr;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(A[mid]);
        root->left = dfs(l, mid - 1);
        root->right = dfs(mid + 1, r);
        return root;
    };
    return dfs(0, (int)A.size() - 1);
}
