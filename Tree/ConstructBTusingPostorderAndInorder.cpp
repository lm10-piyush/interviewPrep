//https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

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
        inorderIdx[A[i]] = i;
    }
    int idx = n - 1;
    function<TreeNode *(int, int)> go = [&](int l, int r) {
        int x = inorderIdx[B[idx]];
        if (x < l or x > r) return (TreeNode *)nullptr;
        TreeNode *root = new TreeNode(B[idx]);
        idx--;
        //right goes first
        if (idx >= 0) {
            root->right = go(x + 1, r);
        }
        //left
        if (idx >= 0) {
            root->left = go(l, x - 1);
        }
        return root;
    };
    TreeNode *root = go(0, n - 1);
    return root;

}
