//https://www.interviewbit.com/problems/count-and-say

string Solution::countAndSay(int A) {
    string curr = "1";
    A--;
    while (A--) {
        string nxt;
        int n = curr.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n and curr[j] == curr[i])
                j++;
            int cnts = j - i;
            nxt += to_string(cnts);
            nxt.push_back(curr[i]);
            i = j - 1;
        }
        curr = nxt;
    }
    return curr;
}
