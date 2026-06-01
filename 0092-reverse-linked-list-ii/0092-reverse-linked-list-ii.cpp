/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL)
            return NULL;

        if(left == right)
            return head;

        ListNode* t = head;
        ListNode* before = NULL;
        int pos = 1;

        // Reach the left position
        while(t != NULL) {
            if(pos < left) {
                before = t;
                t = t->next;
                pos++;
                continue;
            }
            break;
        }

        ListNode* curr = t;
        ListNode* prev = NULL;

        int times = right - left + 1;

        // Reverse the required part
        while(times--) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // t is now the last node of reversed part
        t->next = curr;

        // Edge case: left = 1
        if(before) {
            before->next = prev;
            return head;
        }

        return prev;
    }
};