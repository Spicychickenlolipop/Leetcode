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

//approach1

// class Solution {//recursive solution
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1==NULL){
//             return list2;
//         }
//         if(list2==NULL){
//             return list1;
//         }
//         ListNode* result;
//         if(list1->val<list2->val){
//             result =list1;
//             result->next = mergeTwoLists(list1->next,list2);
//         }else{
//             result = list2;
//             result->next = mergeTwoLists(list1,list2->next);
//         }
//         return result;
//     }
// };




class Solution {//recursive solution
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(list1 != nullptr && list2 != nullptr) {

            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if(list1 != nullptr) {
            curr->next = list1;
        }

        if(list2 != nullptr) {
            curr->next = list2;
        }

        return dummy->next;
    }
};