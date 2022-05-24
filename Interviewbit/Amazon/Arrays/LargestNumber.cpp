//https://www.interviewbit.com/problems/largest-number/

string Solution::largestNumber(const vector<int> &A) {
    vector <string> B;
    for (int i = 0; i < A.size(); ++i) {
        B.push_back(to_string(A[i]));
    }
    sort(B.begin(), B.end(), [](auto a, auto b) {
        return a + b > b + a;
    });
    string ans;
    bool ok = false;
    for (auto i : B) {
        ans += i;
        if (i != "0") ok = true;
    }
    if (!ok) return "0";
    return ans;
}
/*
if sort based on only single elements then the test case: [30, 3] => give 303.
but if we use above algo: it will give: 330.
*/