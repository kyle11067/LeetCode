typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;


ListNode* partition(ListNode* head, int x) {
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        if (head->val < x && head->next->val >= x)
        {
            return head;
        }
        if (head->val < x && head->next->val < x)
        {
            return head;
        }
        if (head->val >= x && head->next->val >= x)
        {
            return head;
        }
        else
        {
            ListNode * temp = head->next;
            head->next->next = head;
            head->next = NULL;
            return temp;

        }
    }
    ListNode * newHead = head;
    ListNode * lowTail = NULL;
    ListNode * highHead = NULL;
    ListNode * prev = head;
    ListNode * cur = head;
    if (cur->val >= x)
    {
        highHead = cur;
        while (cur != NULL)
        {
            if (prev != cur)
            {
                if (cur->val < x)
                {
                    prev->next = cur->next;
                    cur->next = highHead;
                    newHead = cur;
                    lowTail = cur;
                    break;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        if (lowTail == NULL) return head;
    }
    else 
    {
        while (cur != NULL)
        {
            if (prev != cur)
            {
                if (prev->val < x && cur->val >= x)
                {
                    lowTail = prev;
                    highHead = cur;
                    break;
                }
            }

            prev = cur;
            cur = cur->next;
        }
        if (lowTail == NULL || highHead == NULL) return head;
    }
    cur = highHead->next;
    prev = highHead;
    while (cur != NULL)
    {
        if (prev != cur)
        {
            if (cur->val < x)
            {
                prev->next = cur->next;
                cur->next = highHead;
                lowTail->next = cur;
                lowTail = lowTail->next;
                cur = prev;
            }
        }
        prev = cur;
        cur = cur->next;
    }

    return newHead;


}