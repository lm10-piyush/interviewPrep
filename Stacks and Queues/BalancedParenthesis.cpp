// https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string A) {
    stack <char> stk;
    for (auto i : A) {
        if (i == '(') stk.push(i);
        else {
            if (stk.empty())
                return false;
            stk.pop();
        }
    }
    return stk.empty();
}

