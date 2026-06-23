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

// class Solution {
// public:
//     ListNode* reverseLL(ListNode* head){
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* last = reverseLL(head->next);
//         head->next->next=head;
//         head->next = NULL;
//         return last;
//     }
//     void reorderList(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast && fast->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode* rev = reverseLL(slow);

//         ListNode* curr = head;

//         while(rev->next!=NULL){
//             ListNode* tempcurr = curr->next;
//             curr->next = rev;

//             ListNode* temprev = rev->next;
//             rev->next = tempcurr;

//             curr = tempcurr;
//             rev = temprev;
//         }
//     }
// };


// approach2


// class Solution {//tc=O(n)  sc=O(n) usning stack
// public:
//     void reorderList(ListNode* head) {
//         stack<ListNode*> st;
//         ListNode* curr = head;
//         while(curr){
//             st.push(curr);
//             curr = curr->next;
//         }
//         int k = st.size()/2;
//         curr = head;
//         while(k--){
//             ListNode* topNode = st.top();
//             st.pop();

//             ListNode* temp = curr->next;
//             curr->next = topNode;
//             topNode->next = temp;

//             curr = temp;
//         }
//         curr-> next = NULL;
//     }
// };


//approach 3

class Solution {//whitout reverse tc: O(n)  s.c: O(1)/O(n)
public:
    ListNode* curr;
    void solve(ListNode* head){
        if(head == NULL){
            return;
        }
        solve(head->next);
        ListNode* temp = curr->next;
        if(curr->next==NULL){
            return;
        }else if(head == curr){
            head->next = NULL;
            return;
        }
        curr->next = head;
        head->next = (temp==head)?NULL:temp;

        curr = temp;
    }
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);

    }
};