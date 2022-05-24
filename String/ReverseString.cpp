//https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
    stack <string> stk;
    string curr;
    for (auto i : A) {
        if (i == ' ') {
            if (!curr.empty())
                stk.push(curr);
            curr = "";
        }
        else {
            curr.push_back(i);
        }
    }
    if (!curr.empty()) stk.push(curr);
    string ans = "";
    while (!stk.empty()) {
        ans += stk.top() + " ";
        stk.pop();
    }
    ans.pop_back();
    return ans;
}
