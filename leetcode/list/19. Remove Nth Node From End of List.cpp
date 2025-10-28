/*
19. Remove Nth Node From End of List
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

*
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        ListNode* current = head;
        size_t size = 0;
        while (current)
        {
            current = current->next;
            size++;
        }

        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        current = head;
        for (size_t i = 0; i < size - n - 1; i++) {
            current = current->next;
        }

        ListNode* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
        return head;
    }
};