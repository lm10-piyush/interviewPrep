//https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    set <vector <int>> ross;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j + 2 < n; ++j) {
            int k = j + 1, l = n - 1;
            int sum = B - A[i] - A[j];
            while (k < l) {
                int curr = A[k] + A[l];
                if (curr == sum) {
                    ross.insert({A[i], A[j], A[k], A[l]});
                    k++;
                }
                else if (curr > sum) {
                    l--;
                } else k++;
            }
        }
    }
    vector <vector<int>> ans;
    for (auto i : ross) {
        ans.push_back(i);
    }
    return ans;
}
//-10 3 3 4
