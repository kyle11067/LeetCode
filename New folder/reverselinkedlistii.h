typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;


ListNode* reverseList(ListNode* head) {
    
    if (head == NULL)
    {
        return head;
    }
    if(head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        head->next->next = head;
        ListNode * temp = head->next;
        head->next = NULL;
        return temp;
    }
    
    ListNode * curhead = NULL;
    ListNode * cur = head;
    while (cur != NULL)
    {
        ListNode * temp = cur->next;
        cur->next = curhead;
        curhead = cur;
        cur = temp;
    }
    return curhead;

}

ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * cur = head;
        
        ListNode * subprev = NULL;
        ListNode * subhead = head;
        ListNode * tail_end = NULL;
        int i = 0;
        while (cur != NULL && i < right)
        {
            if (i == left - 2)
            {
                subprev = cur;
            }
            if (i == left - 1)
            {
                subhead = cur;
            }
            if (i == right - 1)
            {
                tail_end = cur->next;
                cur->next = NULL;
            }
            cur = cur->next;
            i += 1;
        }


        ListNode * reversed = reverseList(subhead);
        if (subprev != NULL) subprev->next = reversed;
        cur = reversed;
        while (cur != NULL)
        {
            if (cur->next == NULL)
            {
                cur->next = tail_end;
                break;
            }
            cur = cur->next;
        }
        
        if (left == 1) return reversed;
        return head;
    }