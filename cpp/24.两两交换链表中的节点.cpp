/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode *curp = head;
        ListNode *fp = nullptr;
        head = head->next;
        while (curp->next)
        {
            ListNode *p = curp;
            ListNode *q = curp->next;
            p->next = q->next;
            q->next = p;
            if (fp)
                fp->next = q;
            if (p->next)
            {
                curp = p->next;
                fp = p;
            }
        }
        return head;
    }
};
// @lc code=end
