/**
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

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
	ListNode* reverseList(ListNode* head) {
		if (!head) return head;

		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		ListNode* temp = head;

		while (temp != nullptr)
		{
			next = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next;
		}
		return prev;
	}
};