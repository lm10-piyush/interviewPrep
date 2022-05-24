//https://www.interviewbit.com/problems/recover-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
    vector <int> inorder;
    function <void(TreeNode *)> dfs = [&](TreeNode * root) {
        if (root == nullptr) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    };
    dfs(A);
    vector <int> ans;
    for (int i = 1; i < (int)inorder.size(); ++i) {
        if (inorder[i] < inorder[i - 1]) {
            if (ans.empty())
                ans = {inorder[i - 1], inorder[i]};
            else ans = {ans[0], inorder[i]};
        }
    }
    if (ans[0] > ans[1])
        swap(ans[0], ans[1]);
    return ans;
}

/*
 find the inorder tranversal and it should be sorted, except two nodes are swapped.
 How to find those nodes, there are two cases:
 1) they adjacent nodes are swapped that means it has only one inversion.
 2) they are far apart so it has more than 1 inversion.

*/