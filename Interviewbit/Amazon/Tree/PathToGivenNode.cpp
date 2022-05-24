//https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector <int> curr;
    function<int(TreeNode *)> go = [&](TreeNode * root) {
        if (root == nullptr) return 0;
        curr.push_back(root->val);
        if (root->val == B) return 1;
        if (go(root->left) or go(root->right)) return 1;
        curr.pop_back();
        return 0;
    };
    go(A);
    return curr;
}
/*
15 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
5
*/