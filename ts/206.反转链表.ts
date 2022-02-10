/*
 * @lc app=leetcode.cn id=206 lang=typescript
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */
function reverseList(head: ListNode | null): ListNode | null {
  let prev = null,
    cur = head;
  while (cur) {
    const next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}
// @lc code=end
function reverseListRecursive(head: ListNode | null): ListNode | null {
  if (!head || !head.next) return head;
  else {
    const newHead = reverseListRecursive(head.next);
    head.next.next = head;
    head.next = null;
    return newHead;
  }
}
