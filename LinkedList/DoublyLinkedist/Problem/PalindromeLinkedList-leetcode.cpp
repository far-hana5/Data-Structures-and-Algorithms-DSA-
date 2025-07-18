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
    void insertAtTail(ListNode* &head,ListNode* &tail, int val){
         ListNode* newnode = new ListNode(val);
         if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
         }
         tail->next=newnode;
         tail=newnode;
    }

    void reverse(ListNode* &head , ListNode* temp){
        if(temp->next==NULL){
            head=temp;
            return;
        }
        reverse(head,temp->next);
        temp->next->next=temp;
        temp->next=NULL;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* newhead=NULL;
        ListNode* newtail=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
           insertAtTail(newhead,newtail,temp->val) ;
           temp=temp->next;
        }
        reverse(newhead,newhead);

ListNode* temp1=head;
ListNode* temp2=newhead;

while(temp1 !=NULL){
    if(temp1->val != temp2->val){
        return false;
    }
   temp1= temp1->next;
   temp2= temp2->next;
}
return true;
    }
};