/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var levelOrder = function (root) {
  if (!root) return [];
  const ans = [];
  const q = [];
  q.push(root);
  while (q.length) {
    const cur = q.shift();
    ans.push(cur.val);
    if (cur.left) q.push(cur.left);
    if (cur.right) q.push(cur.right);
  }
  return ans;
};
