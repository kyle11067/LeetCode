typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;


ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return head;
    if (head->next == NULL) return head;
    if (head->next->next == NULL)
    {
        if (head->val == head->next->val)
        {
            delete head->next;
            delete head;
            return NULL;
        }
        return head;
    }
    ListNode * newHead = head;
    
    ListNode * prev = head;
    ListNode * cur = head;

    while (cur != NULL)
    {
        if (cur->next != NULL)
        {
            if (cur->next->val == cur->val)
            {
                int val = cur->val;
                while (cur != NULL && cur->val == val)
                {
                    ListNode * temp = cur->next;
                    if (prev == cur)
                    {
                        prev = temp;
                        newHead = prev;
                    } else
                    {
                        prev->next = temp;
                    }
                    delete cur;
                    cur = temp;
                }
            } else
            {
                prev = cur;
                cur = cur->next;
            }
        } else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return newHead;
}