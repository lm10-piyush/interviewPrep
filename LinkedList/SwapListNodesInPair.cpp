//https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if (A == nullptr) return nullptr;
    ListNode *prev = A, *curr = A->next, *p2 = nullptr;
    while (curr != nullptr) {
        ListNode *nxt = curr->next;
        prev->next = nxt;
        curr->next = prev;
        if (p2 == nullptr) A = curr;
        else p2->next = curr;
        p2 = prev;
        prev = nxt;
        if (nxt != nullptr)
            curr = nxt->next;
        else curr = nullptr;
    }
    return A;
}
/*


*/
