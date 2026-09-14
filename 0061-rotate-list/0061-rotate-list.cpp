class Solution {
public:

    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr)
            return head;

        // Find size
        int size = 0;
        ListNode* t = head;

        while (t != nullptr) {
            t = t->next;
            size++;
        }

        k = k % size;

        if (k == 0)
            return head;

        // Reverse complete list
        head = reverseList(head, size);

        // First k nodes
        ListNode* first = head;
        ListNode* second = head;

        for (int i = 1; i < k; i++) {
            second = second->next;
        }

        // Separate first k nodes
        ListNode* rest = second->next;
        second->next = nullptr;

        // Reverse first k
        head = reverseList(first, k);

        // Reverse remaining
        rest = reverseList(rest, size - k);

        // Connect
        first->next = rest;

        return head;
    }
};