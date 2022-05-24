//https://www.interviewbit.com/problems/bst-iterator/

/*
 * To have better solution refere soln in website
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector <int> inorder;
int ptr;
BSTIterator::BSTIterator(TreeNode *root) {
    inorder = vector <int> ();
    ptr = 0;
    function <void(TreeNode *)> go = [&](TreeNode * root) {
        if (!root) return;
        go(root->left);
        inorder.push_back(root->val);
        go(root->right);
    };
    go(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (ptr < (int)inorder.size());
}

/** @return the next smallest number */
int BSTIterator::next() {
    return inorder[ptr++];
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
