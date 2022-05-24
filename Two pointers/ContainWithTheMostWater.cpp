//https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        int height = min(A[l], A[r]);
        int dist = r - l;
        ans = max(ans, height * dist);
        if (A[l] < A[r]) l++;
        else r--;
    }
    return ans;
}
/*
A : [ 1, 20, 20, 1 ]

*/