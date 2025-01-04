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