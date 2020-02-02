/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    // 双指针
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head, *q = head;
        ListNode *fp = nullptr;
        for (int i = 1; i <= n; ++i)
            q = q->next;
        while (q != nullptr)
        {
            q = q->next;
            fp = p;
            p = p->next;
        }
        if (p == head)
            head = p->next;
        else
            fp->next = p->next;
        return head;
    }
};
// @lc code=end
