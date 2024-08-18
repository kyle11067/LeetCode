#include <stack>

typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  } ListNode;

    ListNode* rotateRight(ListNode* head, int k) {
        std::stack<ListNode **> ppNodes;
        ListNode ** cur = &head;
        int c = 0;
        if (head == NULL || head->next == NULL ) return head;

        while(*cur != NULL )
        {
          
            ppNodes.push(cur);
            cur = &(*cur)->next;
            c++;
        }
        k %= c;
        for (size_t i = 0; i < k; i++)
  /* code */
        {
          ListNode ** temp = ppNodes.top();
          ppNodes.pop();
          (*temp)->next = head;
          head = *temp;
          *temp = NULL;
        }

      return head;
    }