//https://www.interviewbit.com/problems/kth-node-from-middle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int middleLength(ListNode *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return (len / 2) + 1;
}

int Solution::solve(ListNode* A, int B) {
    int mid = middleLength(A);
    if (B >= mid) return -1;
    int diff = mid - B - 1;
    while (diff-- > 0) {
        A = A->next;
    }
    return A->val;
}
