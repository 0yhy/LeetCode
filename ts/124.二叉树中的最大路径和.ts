/*
 * @lc app=leetcode.cn id=124 lang=typescript
 *
 * [124] 二叉树中的最大路径和
 */

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

function maxPathSum(root: TreeNode | null): number {
  let ans = -Infinity;
  // 记录当前节点选择左子树或右子树路径所能获取的最大值
  function helper(node: TreeNode | null): number {
    if (!node) return 0;
    // 如果为负值 则不选
    const leftMax = Math.max(0, helper(node.left));
    const rightMax = Math.max(0, helper(node.right));
    // 尝试经过当前节点的值
    ans = Math.max(ans, leftMax + node.val + rightMax);
    // 更新当前节点选择单边路径所能获取的最大值
    return node.val + Math.max(leftMax, rightMax);
  }
}
// @lc code=end
