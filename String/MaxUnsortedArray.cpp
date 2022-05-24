//https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A) {
    vector <int> B = A;
    sort(B.begin(), B.end());
    int l = -1, r = -1;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] != B[i]) {
            if (l == -1) l = r = i;
            else r = i;
        }
    }
    vector <int> ans = { -1};
    if (l > -1) ans = {l, r};
    return ans;
}
/*
 * Sort and compare
*/
