/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function (head) {
  if (!head) return head;
  const m = new Map();
  for (let p = head; p; p = p.next) {
    m.set(p, new Node(p.val));
  }
  for (let p = head; p; p = p.next) {
    m.get(p).next = m.get(p.next) || null;
    m.get(p).random = m.get(p.random) || null;
  }
  return m.get(head);
};
