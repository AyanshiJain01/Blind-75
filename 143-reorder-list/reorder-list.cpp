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
    void reorderList(ListNode* head) {
        if(!head || !head -> next)
        {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow -> next;
        slow -> next = NULL;
        ListNode* prev = NULL;
        while(secondHalf)
        {
            ListNode* temp = secondHalf -> next;
            secondHalf -> next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }

        ListNode* firstHalf = head;
        while(prev)
        {
            ListNode* temp1 = firstHalf -> next;
            ListNode* temp2 = prev -> next;
            firstHalf -> next = prev;
            prev -> next = temp1;
            firstHalf = temp1;
            prev = temp2;
        }
    }
};