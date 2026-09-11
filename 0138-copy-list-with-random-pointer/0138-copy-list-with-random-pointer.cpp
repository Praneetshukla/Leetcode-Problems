/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }

        Node* temp = head;
        Node* next;
        while(temp!= nullptr){
            Node* newnode = new Node(temp->val);
            next=temp->next;
            temp->next=newnode;
            newnode->next=next;
            temp=newnode->next;
        }

        temp = head;
        while(temp!=nullptr){
            Node* copy = temp->next;
            if(temp->random!=nullptr){
                copy->random = temp->random->next;
            }
            temp=copy->next;
        }

        temp = head;
        Node* copyhead = head->next;
        while(temp!=nullptr){
            Node* copy = temp->next;
            temp->next = copy->next;
            if(copy->next!=nullptr){
                copy->next = copy->next->next;
            }
            temp=temp->next;
        }
        return copyhead;
    }
};