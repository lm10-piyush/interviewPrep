//https://www.interviewbit.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map <int, UndirectedGraphNode*> mp;
    function<void(UndirectedGraphNode *)> dfs = [&](UndirectedGraphNode * root) {
        mp[root->label] = new UndirectedGraphNode(root->label);
        for (auto i : root->neighbors) {
            if (!mp.count(i->label)) {
                dfs(i);
            }
        }
    };

    dfs(node);
    UndirectedGraphNode *graph = mp[node->label];
    set <UndirectedGraphNode *> used;
    function<void(UndirectedGraphNode *, UndirectedGraphNode *)> go = [&](UndirectedGraphNode * root, UndirectedGraphNode * root2) {
        used.insert(root);
        int m = root2->neighbors.size();
        for (int i = 0; i < m; ++i) {
            int x = root2->neighbors[i]->label;
            root->neighbors.push_back(mp[x]);
        }
        for (int i = 0; i < m; ++i) {
            if (!used.count(root->neighbors[i])) {
                go(root->neighbors[i], root2->neighbors[i]);
            }
        }
    };
    go(graph, node);
    return graph;
}
