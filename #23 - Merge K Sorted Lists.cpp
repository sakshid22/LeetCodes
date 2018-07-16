//23
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
ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
if(lists.empty()) return NULL;
int n=lists.size();
    while(n>1)
    {
        for(int i=0; i<n/2;i++)
        lists[i]= mergeLists(lists[i],lists[n-1-i]);
    n=(n+1)/2;
    }
return lists[0];
}
    
private:
ListNode *mergeLists(ListNode *head1, ListNode *head2)
{
ListNode *new_head = new ListNode(0);
ListNode *run = new_head;
ListNode *run1=head1;
ListNode *run2=head2;
    while(run1 && run2)
    {
        if(run1->val <= run2->val)
        {
        run->next=run1;
        run1=run1->next;
        }
        else
        {
        run->next =run2;
        run2 =run2->next;
        }
    run=run->next;
    }
run->next = run1 ? run1:run2;
return new_head->next;
       
    }
};