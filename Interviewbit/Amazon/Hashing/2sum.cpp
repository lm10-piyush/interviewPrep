//https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map <int, int> mp;
    for (int i = 0; i < (int)A.size(); ++i) {
        int rem = B - A[i];
        if (mp.count(rem)) {
            return {mp[rem] + 1, i + 1};
        }
        if (!mp.count(A[i])) mp[A[i]] = i;
    }
    return {};
}
