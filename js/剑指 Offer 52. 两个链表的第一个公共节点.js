/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {
  // 首尾相连
  let p = headA;
  while (p.next) p = p.next;
  p.next = headB;
  // 判环
  let slow = headA,
    fast = headA;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) break;
  }
  if (slow !== fast) {
    p.next = null;
    return null;
  }
  // 找环起点
  slow = headA;
  while (slow !== fast) {
    slow = slow.next;
    fast = fast.next;
  }
  // 断开首尾
  p.next = null;
  return slow;
};
