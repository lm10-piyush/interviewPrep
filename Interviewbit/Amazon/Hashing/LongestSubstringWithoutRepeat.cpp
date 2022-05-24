//https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {
    unordered_map <char, int> cnts;
    int ans = 0;
    for (int i = 0, j = 0; i < A.size(); ++i) {
        cnts[A[i] - 'a']++;
        while (cnts[A[i] - 'a'] > 1) {
            cnts[A[j] - 'a']--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
