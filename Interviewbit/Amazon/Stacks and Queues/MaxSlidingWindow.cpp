//https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    deque <int> dq;
    for (int i = 0; i < B; ++i) {
        while (!dq.empty() and A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    vector <int> ans;
    ans.push_back(A[dq.front()]);

    for (int i = B; i < n; ++i) {
        while (!dq.empty() and i - dq.front() >= B)
            dq.pop_front();
        while (!dq.empty() and A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(A[dq.front()]);
    }

    return ans;
}
