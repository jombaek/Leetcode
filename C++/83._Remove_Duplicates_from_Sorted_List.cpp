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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* cur = head;

        while (cur)
        {
            ListNode* nextNode = cur->next;

            while (nextNode && cur->val == nextNode->val)
                nextNode = nextNode->next;
            
            cur->next = nextNode;
            cur = nextNode;
        }

        return head;
    }
};