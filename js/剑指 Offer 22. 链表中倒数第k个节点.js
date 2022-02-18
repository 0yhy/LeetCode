/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function (head, k) {
  let p = head,
    q = head;
  for (let i = 0; i < k - 1; ++i) {
    q = q.next;
  }
  while (q.next) {
    p = p.next;
    q = q.next;
  }
  return p;
};
