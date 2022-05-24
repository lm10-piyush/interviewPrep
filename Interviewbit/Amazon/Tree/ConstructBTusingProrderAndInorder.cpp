//https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    map <int, int> inorderIdx;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        inorderIdx[B[i]] = i;
    }
    int idx = 0;
    function<TreeNode *(int, int)> go = [&](int l, int r) {
        int x = inorderIdx[A[idx]];
        if (x < l or x > r) return (TreeNode *)nullptr;
        TreeNode *root = new TreeNode(A[idx]);
        idx++;
        //left goes first
        if (idx < n) {
            root->left = go(l, x - 1);
        }
        //right
        if (idx < n) {
            root->right = go(x + 1, r);
        }

        return root;
    };
    TreeNode *root = go(0, n - 1);
    return root;
}
/*
Iterate on preorder from left to right.
Use preorder to find which would be next node, and inorder would give the information about where should
that node be placed: left, right, not in the subtree. To do that we need the index of current and and next node in
inorder sequence, the index of next node must lie inside the subtree range of current node.

*/