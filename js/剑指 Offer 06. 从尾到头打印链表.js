/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrint = function (head) {
  const ans = [];
  for (const p = head; p; p = p.next) {
    ans.push(p.val);
  }
  return ans.reverse();
};
