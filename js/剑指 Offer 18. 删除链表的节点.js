/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function (head, val) {
  const dummy = new ListNode();
  dummy.next = head;
  for (let p = head, q = dummy; p; p = p.next, q = q.next) {
    if (p.val === val) q.next = p.next;
  }
  return dummy.next;
};
