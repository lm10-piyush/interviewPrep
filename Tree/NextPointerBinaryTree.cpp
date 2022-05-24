//https://www.interviewbit.com/problems/next-pointer-binary-tree/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/*
 Go in the level order traversal and maintain the previous node and its depth.
*/
void Solution::connect(TreeLinkNode* A) {
    queue <pair<TreeLinkNode *, int>> q;
    q.push({A, 0});
    TreeLinkNode *prev = nullptr;
    int d = -1;
    while (!q.empty()) {
        TreeLinkNode *u = q.front().first;
        int currD = q.front().second; q.pop();
        if (d == currD) {
            prev->next = u;
        }
        prev = u;
        d = currD;
        if (u->left) {
            q.push({u->left, currD + 1});
        }
        if (u->right) {
            q.push({u->right, currD + 1});
        }
    }

}
