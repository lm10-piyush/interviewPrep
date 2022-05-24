//https://www.interviewbit.com/problems/diagonal-traversal/
// https://pastebin.com/YJyYFjzD

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
	map <int, vector <int>> digs;
	function<void(TreeNode *, int)> go = [&](TreeNode * root, int d) {
		if (root == nullptr) return;
		digs[d].push_back(root->val);
		go(root->left, d + 1);
		go(root->right, d);
	};
	go(A, 0);
	vector <int> ans;
	for (auto i : digs) {
		for (auto j : i.second)
			ans.push_back(j);
	}
	return ans;
}
/*
 * Giving some name to each diagonal, moving to right child doesn't changes the name but moving to the
 left child does.
 Current diagonal : d, moving to right child and the diagonal remains same,
 but moving to child should give to the new diagonal name uniquely, lets say it is d+1 (always unique).
*/

