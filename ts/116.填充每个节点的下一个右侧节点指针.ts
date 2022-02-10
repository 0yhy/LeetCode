/*
 * @lc app=leetcode.cn id=116 lang=typescript
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     left: Node | null
 *     right: Node | null
 *     next: Node | null
 *     constructor(val?: number, left?: Node, right?: Node, next?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function connect(root: Node | null): Node | null {
  function helper(node: Node | null, parent: Node | null): void {
    if (node) {
      if (parent.right !== node) node.next = parent.right;
      else {
        if (parent.next) node.next = parent.next.left;
        else node.next = null;
      }
      helper(node.left, node);
      helper(node.right, node);
    }
  }
  if (root) {
    helper(root.left, root);
    helper(root.right, root);
  }
  return root;
}
// @lc code=end
