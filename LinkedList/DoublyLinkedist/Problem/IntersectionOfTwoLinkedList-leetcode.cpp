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
        ListNode* temp1=headA;
        ListNode* temp2= headB;

        while(temp1!=NULL){
           while(temp2!=NULL){
             if(temp1==temp2){
                return temp1;
             }

             temp2=temp2->next;
           }
temp2= headB;
          temp1=temp1->next;
        }
        return NULL;
    }
};