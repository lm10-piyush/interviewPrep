//https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    int ans = 0, curr = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == ' ') {
            curr = 0;
        }
        else {
            curr++;
            ans = curr;
        }
    }
    return ans;
}
