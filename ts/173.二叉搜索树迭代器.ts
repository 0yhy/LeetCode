/*
 * @lc app=leetcode.cn id=173 lang=typescript
 *
 * [173] 二叉搜索树迭代器
 */
class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BSTIterator {
  stack: TreeNode[];
  cur: TreeNode | null;
  constructor(root: TreeNode | null) {
    this.stack = [];
    this.cur = root;
  }
  next(): number {
    while (this.cur) {
      this.stack.push(this.cur);
      this.cur = this.cur.left;
    }
    this.cur = this.stack.pop();
    const { val } = this.cur;
    this.cur = this.cur.right;
    return val;
  }

  hasNext(): boolean {
    return this.cur !== null || Boolean(this.stack.length);
  }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
// @lc code=end
