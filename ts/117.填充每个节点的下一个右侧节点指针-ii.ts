/*
 * @lc app=leetcode.cn id=117 lang=typescript
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
  function firstChild(node: Node | null): Node | null {
    return node.left || node.right || null;
  }
  function helper(node: Node | null, parent: Node | null) {
    if (node && !node.next) {
      if (parent.right && parent.right !== node) {
        node.next = parent.right;
      } else {
        parent = parent.next;
        while (parent && !parent.left && !parent.right) parent = parent.next;
        node.next = parent ? firstChild(parent) : null;
      }
      // 先递归next很重要！不然子节点如果先被递归到了，并且依赖爸爸的next，就会出问题
      helper(node.next, parent);
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
