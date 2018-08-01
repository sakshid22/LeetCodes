//234

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
    bool isPalindrome(ListNode* head) {
        
  /*      ListNode *temp = head;
        ListNode *temp1 = head2;
        while(temp->next != null)
        {
            temp=temp->next;
        }
        while(temp1->next!= temp)
        {
            if(temp1->next == temp->prev)
            
        }
 */
        if(!head || !head->next) return true;
        ListNode *slow =head, *fast= head->next, *prev=NULL;
            while(true)
            {
                if(!fast->next)
                {
                    fast=slow->next;
                    slow->next=prev;
                    break;
                }
                else if(!fast->next->next)
                {
                    fast=slow->next->next;
                    slow->next=prev;
                    break;
                }
                else
                {
                    fast=fast->next->next;
                    ListNode *temp=slow->next;
                    slow->next=prev;
                    prev=slow;
                    slow=temp;
                }
            }
        while(slow && fast)
        {
            if(slow ->val !=fast->val) return false;
            slow = slow->next;
            fast=fast->next;
        }
        return true;
    }
};