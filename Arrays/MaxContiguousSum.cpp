//https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

//Kadane algo

int Solution::maxSubArray(const vector<int> &A) {
    int curr = 0, ans = INT_MIN;
    for (int i : A) {
        curr += i;
        ans = max(ans, curr);
        curr = max(curr, 0);
    }
    return ans;
}
