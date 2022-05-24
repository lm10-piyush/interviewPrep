//https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if (A == nullptr) return nullptr;
    ListNode *slow = A, *fast = A;
    do {
        if (fast == nullptr or fast->next == nullptr)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;

    } while (slow != fast);
    slow = A;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
