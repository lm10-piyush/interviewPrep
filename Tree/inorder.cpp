
//https://www.interviewbit.com/problems/inorder-traversal/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector <int> inorder;
    function <void(TreeNode *)> dfs = [&](TreeNode * root) {
        if (root == nullptr) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    };
    dfs(A);
    return inorder;
}
