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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *even=new ListNode();
        ListNode *cur=head;
        ListNode *ecur=even;
        ListNode *prev;
        while(cur && cur->next){
            ecur->next=cur->next;
            cur->next=ecur->next->next;
            // prev=cur;
            if(cur->next==NULL) prev=cur;
            cur=cur->next;
            ecur=ecur->next;
        }
        ecur->next=NULL;
        if(cur==NULL) prev->next=even->next;
        else cur->next=even->next;
        return head;
        
        
    }
};