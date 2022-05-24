//https://www.interviewbit.com/problems/combinations/

vector<vector<int> > Solution::combine(int A, int B) {
    vector <vector <int>> ans;
    int n = A, k = B;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == k) {
            vector <int> curr;
            for (int j = 0; j < n; ++j) {
                if (mask >> j & 1)
                    curr.push_back(j + 1);
            }
            ans.push_back(curr);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
