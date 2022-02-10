/*
 * @lc app=leetcode.cn id=138 lang=typescript
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     next: Node | null
 *     random: Node | null
 *     constructor(val?: number, next?: Node, random?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: Node | null): Node | null {
  let p = head,
    q = new Node(),
    prev = new Node(),
    r = prev;
  const map = new Map();
  while (p) {
    q = new Node(p.val, null, null);
    map.set(p, q);
    prev.next = q;
    p = p.next;
    prev = q;
  }
  p = head;
  r = r.next;
  const ans = r;
  while (r) {
    r.random = map.get(p.random);
    (p = p.next), (r = r.next);
  }
  return ans;
}
// @lc code=end
