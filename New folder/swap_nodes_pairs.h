
//  Definition for singly-linked list.
#include <string>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode * swapPairs(ListNode * head) {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            return head;
        }

        ListNode * new_head = NULL;

        ListNode** ptr_1 = &head;
       

        while (*ptr_1 != NULL)
        {
            ListNode * temp = (*ptr_1)->next;
            if (temp == NULL)
            {
                break;
            }
            (*ptr_1)->next = temp->next;
            temp->next = *ptr_1;
            if (new_head == NULL)
            {
                new_head = temp;
            }
            
            *ptr_1 = temp;
            ptr_1 = &(*ptr_1)->next->next;
            
        }

        return new_head;
}