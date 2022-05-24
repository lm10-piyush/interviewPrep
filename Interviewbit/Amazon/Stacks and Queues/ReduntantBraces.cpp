//https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    stack <char> stk;
    for (auto i : A) {
        if (i == ')') {
            int cnts = 0;
            while (stk.top() != '(') {
                stk.pop();
                cnts++;
            }
            if (cnts <= 1) return 1;
            stk.pop();
        }
        else {
            stk.push(i);
        }
    }
    return 0;
}
