//https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //solution in O(n) time and O(1) space
    //merge l2 in l1
    //Idea is to keep maintain the current and previous pointer for l1, current for l2
    if (l1 == nullptr) return l2;
    ListNode *prv = nullptr, *curr = l1, *curr2 = l2;

    while (curr != nullptr and curr2 != nullptr) {
        if (curr->val > curr2->val) {
            ListNode *next2 = curr2->next;
            curr2->next = curr;
            if (prv == nullptr) {
                l1 = curr2;
            } else prv->next = curr2;
            prv = curr2;
            curr2 = next2;
        }
        else {
            prv = curr;
            curr = curr->next;
        }
    }

    //if l2 is still remain and l1 is finished, then just append remain l2
    if (curr2 != nullptr) {
        prv->next = curr2;
    }
    return l1;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *head = nullptr;
    for (auto i : A) {
        head = mergeTwoLists(head, i);
    }
    return head;
}
