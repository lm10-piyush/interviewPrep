//https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector <int> ans;
    stack <int> stk; stk.push(-1);
    for (int i : A) {
        while (stk.top() >= i)
            stk.pop();
        ans.push_back(stk.top());
        stk.push(i);
    }
    return ans;
}
