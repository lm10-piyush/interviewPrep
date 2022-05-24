//https://www.interviewbit.com/problems/commutable-islands/

struct DSU {
  vector <int> parent, size;
  int components;
  DSU(int n) {
    parent.resize(n + 1);
    size.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      parent[i] = i;
    components = n;
  }

  //get leader
  int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }

  bool unite(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return false;
    if (size[x] < size[y]) swap(x, y);
    components--; //components decreases with union
    parent[y] = x;
    size[x] += size[y];
    return true;
  }
};

//Kruskal

int Solution::solve(int A, vector<vector<int> > &B) {
  vector <array<int, 3>> edges;
  for (auto i : B) {
    edges.push_back({i[2], i[0], i[1]});
  }
  sort(edges.begin(), edges.end());
  DSU d(A);
  int cost = 0;
  for (auto i : edges) {
    if (!d.unite(i[1], i[2])) continue;
    cost += i[0];
  }
  return cost;
}


/*
A : 4
B :
[
  [1, 2, 1]
  [2, 3, 2]
  [3, 4, 4]
  [1, 4, 3]
]

4
4 3 1 2 1 2 3 2 3 4 4 1 4 3
*/