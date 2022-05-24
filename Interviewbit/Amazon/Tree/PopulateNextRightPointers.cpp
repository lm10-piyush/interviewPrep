//https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    vector <TreeLinkNode *> order;
    map <TreeLinkNode *, int> lvl;
    queue <TreeLinkNode *> q;
    q.push(A);
    lvl[A] = 0;

    while (!q.empty()) {
        TreeLinkNode *u = q.front(); q.pop();
        order.push_back(u);
        if (u->left) {
            q.push(u->left);
            lvl[u->left] = lvl[u] + 1;
        }
        if (u->right) {
            q.push(u->right);
            lvl[u->right] = lvl[u] + 1;
        }
    }
    int n = order.size();
    for (int i = 0; i + 1 < n; ++i) {
        TreeLinkNode *u = order[i];
        TreeLinkNode *v = order[i + 1];
        if (lvl[u] == lvl[v]) {
            u->next = v;
        }
    }

}

