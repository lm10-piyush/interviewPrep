
//https://www.interviewbit.com/problems/generate-all-parentheses/

int Solution::isValid(string A) {
    stack <char> stk;
    auto check = [&](char a, char b) {
        if (a == '(' and b == ')') return 1;
        if (a == '{' and b == '}') return 1;
        if (a == '[' and b == ']') return 1;
        return 0;
    };
    for (char i : A) {
        if (i == '(' or i == '{' or i == '[')
            stk.push(i);
        else {
            if (stk.empty() or !check(stk.top(), i)) return 0;
            stk.pop();
        }
    }
    return stk.empty();
}
