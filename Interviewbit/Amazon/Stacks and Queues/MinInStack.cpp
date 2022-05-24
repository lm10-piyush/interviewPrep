//https://www.interviewbit.com/problems/min-stack/

stack <pair<int, int>> stk;
MinStack::MinStack() {
    stk = stack <pair<int, int>> ();
}

void MinStack::push(int x) {
    if (stk.empty()) stk.push({x, x});
    else stk.push({x, min(stk.top().second, x)});
}

void MinStack::pop() {
    if (!stk.empty())
        return stk.pop();
}

int MinStack::top() {
    if (stk.empty()) return -1;
    return stk.top().first;
}

int MinStack::getMin() {
    if (!stk.empty())
        return stk.top().second;
    return -1;
}


