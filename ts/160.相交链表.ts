/*
 * @lc app=leetcode.cn id=160 lang=typescript
 *
 * [160] 相交链表
 */
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

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

function getIntersectionNode(
  headA: ListNode | null,
  headB: ListNode | null
): ListNode | null {
  // 将A链表的首尾连接成环
  let p = headA;
  while (p.next) p = p.next;
  p.next = headA;
  // 快慢指针判环
  let f = headB,
    s = headB;
  while (f && f.next) {
    (f = f.next.next), (s = s.next);
    if (f === s) break;
  }
  // 链表中无环，返回null
  if (!f || !f.next) {
    p.next = null;
    return null;
  }
  f = headB;
  while (f !== s) (f = f.next), (s = s.next);
  p.next = null;
  return s;
}
// @lc code=end
