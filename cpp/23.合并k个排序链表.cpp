/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (!lists.size())
            return nullptr;
        ListNode *tmp = lists[0];
        for (int i = 1; i < lists.size(); ++i)
            tmp = mergeTwoLists(tmp, lists[i]);
        return tmp;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val > l2->val)
            swap(l1, l2);
        ListNode *head = new ListNode(l1->val);
        ListNode *p = head;
        l1 = l1->next;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                ListNode *q = new ListNode(l1->val);
                l1 = l1->next;
                p->next = q;
            }
            else
            {
                ListNode *q = new ListNode(l2->val);
                l2 = l2->next;
                p->next = q;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        return head;
    }
};
// @lc code=end
