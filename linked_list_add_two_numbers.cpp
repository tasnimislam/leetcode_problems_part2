// https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=linked-list

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* addLinkedList = new ListNode(0);
        ListNode* result = addLinkedList;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            addLinkedList->val = (l1->val+l2->val + carry)%10;
            carry = (l1->val+l2->val + carry)/10;

            l1 = l1->next;
            l2 = l2->next;

            if(l1==nullptr && l2!=nullptr){
                l1 = new ListNode(0);
            }

            else if(l2==nullptr && l1!=nullptr){
                l2 = new ListNode(0);
            }

            else if(carry!=0 && l1==nullptr && l2==nullptr){
                l1 = new ListNode(0);
                l2 = new ListNode(0);
            }

            else if(l1== nullptr && l2== nullptr && carry==0){
                break;
            }

            addLinkedList->next = new ListNode(0);
            addLinkedList = addLinkedList->next;

        }

        return result;
    }
};

int main() {
    // Create a linked list: 2->4->3
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);

    // Create a linked list: 5->6->4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Reverse the linked list
    Solution solution;
    ListNode* addedHead = solution.addTwoNumbers(l1, l2);

    // Print the reversed list
    cout << "Added List: ";
    printList(addedHead);


    return 0;
}




