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
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int data = l1->val + l2->val;
        ListNode *ans = new ListNode(data % 10);
        ListNode *p = ans;
        int carry = data / 10;
        p1 = p1->next;
        p2 = p2->next;
        while (p1 || p2)
        {
            int v1 = 0, v2 = 0;
            if (p1)
            {
                v1 = p1->val;
                p1 = p1->next;
            }
            if (p2)
            {
                v2 = p2->val;
                p2 = p2->next;
            }
            int data = carry + v1 + v2;
            carry = data / 10;
            ListNode *q = new ListNode(data % 10);
            p->next = q;
            p = q;
        }
        while (carry)
        {
            ListNode *q = new ListNode(carry % 10);
            carry /= 10;
            p->next = q;
            p = q;
        }
        return ans;
    }
};
// @lc code=end
