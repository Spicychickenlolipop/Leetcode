/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(true){
            if(tempA == tempB)
                return tempA;
            if(tempA)
                tempA = tempA->next;
            else
                tempA = headA;
            
            if(tempB)
                tempB = tempB->next;
            else
                tempB = headB;
            
        }
        return NULL;
    }
};