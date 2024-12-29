typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        if (head->next == NULL)
        {
            return head;
        }

        ListNode * prev = head;
        ListNode * cur = head;

        while (cur != NULL)
        {
            if (prev != cur)
            {
                while (cur != NULL && cur->val == prev->val )
                {
                    ListNode * temp = cur->next;
                    delete cur;
                    prev->next = temp;
                    cur = temp;
                }   
            }
            prev = cur;
            if (cur != NULL)
            {
                cur = cur->next;
            }
        }

        return head;
    }