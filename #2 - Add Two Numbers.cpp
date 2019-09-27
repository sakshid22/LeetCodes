// #2 - add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int s=0;
        int c=0;
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        while(l1!=NULL || l2!=NULL || c!=0)
        {
            s=0;
            if(l1)
            {
                s=s+l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                s=s+l2->val;
                l2=l2->next;
            }
            s=s+c;
            c=s/10;
            s=s%10;
            
            ListNode *t=new ListNode(s);
            tail->next=t;
            tail=t;
        }
        return head->next;
    }
};