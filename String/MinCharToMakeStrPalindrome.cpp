//https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

vector <int> kmpPreProcess(string &pattern) {

    vector <int> piTable((int)pattern.size(), 0);  //(piTable[i] = x) => longest string which is a suff at i (i-x+1...i) and prefix (1...x)
    for (int i = 1, j = 0; i < (int)pattern.size(); ++i) {
        while (j > 0 and pattern[j] != pattern[i])
            j = piTable[j - 1]; //key step, you know why it works?
        assert(0 <= j and j <= (int)pattern.size());

        if (pattern[j] == pattern[i]) j++;
        piTable[i] = j;
    }
    return piTable;
}

//O(n2) is too slow
int Solution::solve(string A) {
    string t = A + "?";
    reverse(A.begin(), A.end());
    t = t + A;
    vector <int> piTable = kmpPreProcess(t);
    int n = A.size();
    return n - piTable.back();
}
/*
The reframed ques is: remove the minimum number of suffix characters such that remaining prefx is a palindrome.
0                       23
eylfpbnpljvrvipyamyehwqnq?qnqwheymaypivrvjlpnbpflye
ans = 24
abcbade
edabcba

t = s + "?" + reverse(s)
Now apply KMP, and take the last value of piTable, because we need prefix palindrome.
*/