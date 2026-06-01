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
#define null NULL
#define Node ListNode
#define data val
#define ed endl
    void reverse(Node* head, int times){
        Node* curr = head;
        Node* prev = null;
        while(times--){
            Node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head==null)
        return null;
        Node* left=head;
        Node* right;
        Node* res = null;
        Node* prevleft=null;
        int size=2;
        while(true){
            right= left;
            for(int i=0;i<size-1;i++){
                if(right==null)
                break;
                right=right->next;
            }
            if(right){
                Node* nextleft=right->next;
                reverse(left,size);
                if(prevleft)
                prevleft->next=right;
                prevleft=left;
                if(res==null)
                res=right;

                left=nextleft;
            }else{
                if(prevleft)
                prevleft->next=left;
                if(res==null)
                res=left;

                break;
            }
        }
        return res;
    }
};