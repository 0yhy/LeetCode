/*
 * @lc app=leetcode.cn id=236 lang=typescript
 *
 * [236] 二叉树的最近公共祖先
 */
class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  parent?: TreeNode | null;
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
function lowestCommonAncestor(
  root: TreeNode | null,
  p: TreeNode | null,
  q: TreeNode | null
): TreeNode | null {
  if (!root || root === p || root === q) return root;
  const left = lowestCommonAncestor(root.left, p, q);
  const right = lowestCommonAncestor(root.right, p, q);
  return left && right ? root : left || right;
}

// @lc code=end

function lowestCommonAncestor1(
  root: TreeNode | null,
  p: TreeNode | null,
  q: TreeNode | null
): TreeNode | null {
  // 先遍历一遍存爸爸
  // 从p出发存下p所有的爸爸
  //
  const parents = new Set();
  function traverse(root: TreeNode | null) {
    if (root.left) {
      root.left.parent = root;
      traverse(root.left);
    }
    if (root.right) {
      root.right.parent = root;
      traverse(root.right);
    }
  }
  traverse(root);
  for (let node = p; node !== root; node = node.parent) {
    parents.add(node.parent);
  }
  for (let node = q; node !== root; node = node.parent) {
    if (parents.has(node.parent)) return node.parent;
  }
}
