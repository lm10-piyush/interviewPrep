//https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector <vector <int>> ans;
    vector <int> curr;
    function <void(TreeNode *, long long)> go = [&](TreeNode * root, long long sum) {
        if (root == nullptr) return;
        long long s = sum + root->val;
        curr.push_back(root->val);
        if (!root->left and !root->right) {
            if (s == B) ans.push_back(curr);
        }
        go(root->left, s);
        go(root->right, s);
        curr.pop_back();
    };
    go(A, 0);
    return ans;
}
