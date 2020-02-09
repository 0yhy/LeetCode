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
    // 分治法，类归并排序
    ListNode *mergeKLists(vector<ListNode *> &Lists)
    {
        int arrSize = Lists.size();
        if (!arrSize)
            return nullptr;
        // cnt为每次待合并的两个链表在Lists中的下标值的差
        int cnt = 1;
        // totalCnt为剩余未合并的链表数
        int totalCnt = arrSize;
        while (cnt < arrSize)
        {
            // 如果待合并链表数为奇数，i + cnt小于 arrSize - 1
            // 如果待合并链表数为偶数，i + cnt小于 arrSize 即可
            for (int i = 0; i + cnt < (totalCnt % 2 ? arrSize - 1 : arrSize); i += cnt * 2)
                Lists[i] = mergeTwoLists(Lists[i], Lists[i + cnt]);
            cnt *= 2;
            totalCnt = totalCnt / 2 + totalCnt % 2;
        }
        return Lists[0];
    }
    // 暴力解法，两两合并，最后一个点超时
    ListNode *mergeKListsBruteForce(vector<ListNode *> &lists)
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
