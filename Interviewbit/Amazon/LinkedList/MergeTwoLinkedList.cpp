//https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    //maintain, the prev, curr1 pointer of l1, and curr2 of l2
    ListNode *prev = nullptr, *curr1 = l1, *curr2 = l2;
    while (curr1 and curr2) {
        if (curr1->val > curr2->val) {
            ListNode *nxt = curr2->next;
            curr2->next = curr1;
            if (prev == nullptr) {
                l1 = curr2;
            } else prev->next = curr2;
            prev = curr2;
            curr2 = nxt;
        }
        else {
            prev = curr1;
            curr1 = curr1->next;
        }
    }
    if (curr2 != nullptr) {
        prev->next = curr2;
    }

    return l1;
}
/*
 [ 4 -> 5 -> 6 ]
B : [ 1 -> 2 -> 3 ]

*/