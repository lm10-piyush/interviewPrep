//https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &A) {
    function <TreeNode *(int, int)> go = [&](int l, int r) {
        if (l > r) return (TreeNode *)nullptr;
        int idx = l;
        for (int i = l; i <= r; ++i) {
            if (A[i] > A[idx]) {
                idx = i;
            }
        }

        TreeNode *root = new TreeNode(A[idx]);
        root->left = go(l, idx - 1);
        root->right = go(idx + 1, r);
        return root;
    };
    return go(0, (int)A.size() - 1);
}
