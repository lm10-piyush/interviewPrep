//https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &A) {
    vector <int> dp;
    for (int i : A) {
        int idx = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (idx == (int)dp.size())
            dp.push_back(i);
        else dp[idx] = i;
    }
    return (int)dp.size();
}
