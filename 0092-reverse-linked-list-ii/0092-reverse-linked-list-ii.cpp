class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 1. Find node just before 'left'
        ListNode* before = dummy;

        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        // 2. Reverse the sublist
        ListNode* curr = before->next;
        ListNode* prev = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Reconnect
        ListNode* start = before->next;

        before->next = prev;
        start->next = curr;

        return dummy->next;
    }
};