/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverselist (ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head -> next == nullptr){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= nullptr && fast->next != nullptr){
            slow=slow->next;
            fast = fast->next ->next;
        }
        ListNode* secondhalf = reverselist(slow);

        ListNode* first = head;
        ListNode* second = secondhalf;

        while(second!=nullptr){
            if(first ->val != second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;

    }

};