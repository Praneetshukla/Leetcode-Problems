class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;
                Node* childTail = curr->child;

                while (childTail->next != nullptr) {
                    childTail = childTail->next;
                }

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                if (nextNode != nullptr) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};