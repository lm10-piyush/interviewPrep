// https://www.interviewbit.com/problems/k-largest-elements/

vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end(), greater <int>());
    vector <int> ans;
    int i = 0;
    while (B--) {
        ans.push_back(A[i++]);

    }
    return ans;
}
