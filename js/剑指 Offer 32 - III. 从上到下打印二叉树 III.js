/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
  if (!root) return [];
  const ans = [];
  const q = [];
  q.push(root);
  let flag = false;
  while (q.length) {
    let len = q.length;
    const tmp = [];
    while (len--) {
      const cur = q.shift();
      if (cur.left) q.push(cur.left);
      if (cur.right) q.push(cur.right);
      tmp.push(cur.val);
    }
    if (flag) tmp.reverse();
    ans.push(tmp);
    flag = !flag;
  }
  return ans;
};
