/*
160. Intersection of Two Linked Lists
Solved
Easy
Topics
premium lock icon
Companies
Given the heads of two singly linked - lists headA and headB, return the node at which the two lists intersect.If the two linked lists have no intersection at all, return null.

*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            if (!headA || !headB) return nullptr;

            ListNode* tempA = headA;
            ListNode* tempB = headB;
            while (tempA)
            {
                while (tempB)
                {
                    if (tempB == tempA)
                        return tempB;
                    tempB = tempB->next;
                }
                tempB = headB;
                tempA = tempA->next;
            }
            return nullptr;
        }
};