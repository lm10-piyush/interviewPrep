/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector <int> postOrder;
    function<void(TreeNode *)> dfs = [&](TreeNode * root) {
        if (root == nullptr) return;
        dfs(root->left);
        dfs(root->right);
        postOrder.push_back(root->val);
    };
    dfs(A);
    return postOrder;
}
