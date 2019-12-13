/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        long long ans = getNumber(l1) + getNumber(l2);
        ListNode *head = new ListNode(ans % 10);
        ans /= 10;
        ListNode *p = head;
        while (ans)
        {
            ListNode *q = new ListNode(ans % 10);
            ans /= 10;
            p->next = q;
            p = q;
        }
        return head;
    }
    long long getNumber(ListNode *l)
    {
        vector<int> v;
        long long ans = 0;
        ListNode *p = l;
        while (p != nullptr)
        {
            v.push_back(p->val);
            p = p->next;
        }
        for (int i = v.size() - 1; i >= 0; --i)
        {
            ans += v[i];
            ans *= 10;
        }
        ans /= 10;
        return ans;
    }
};
// @lc code=end
