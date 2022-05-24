//https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    map <int, int> cnts;
    for (int i = 0; i < B - 1; ++i) {
        cnts[A[i]]++;
    }
    vector <int> ans;
    for (int i = B - 1; i < n; ++i) {
        cnts[A[i]]++;
        ans.push_back(cnts.size());
        int last = i - B + 1;
        if (--cnts[A[last]] == 0)
            cnts.erase(A[last]);
    }
    return ans;
}
