class Solution {
public:

    ListNode *dummy = new ListNode(101);
    int start = -1;

    void solve(ListNode *head, ListNode *prev) {

        if(head == NULL) 
            return;

        if(head->next == NULL) {
            if(start == -1)
                dummy->next = head;
            else
                prev->next = head;
            return;
        }

        ListNode *temp = head->next;
        ListNode *t = head;
        ListNode *store = temp->next;

        t->next = store;
        temp->next = t;

        if(prev != head)
            prev->next = temp;

        if(start == -1) {
            dummy->next = temp;
            start = 1;
        }

        solve(store, t);
    }

    ListNode* swapPairs(ListNode* head) {
        dummy->next = NULL;
        //start = -1;

        solve(head, head);

        return dummy->next;
    }
};