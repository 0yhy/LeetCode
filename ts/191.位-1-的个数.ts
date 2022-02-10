/*
 * @lc app=leetcode.cn id=191 lang=typescript
 *
 * [191] 位1的个数
 */

// @lc code=start
function hammingWeight(n: number): number {
  let cnt = 0;
  while (n) {
    ++cnt;
    n &= n - 1;
  }
  return cnt;
}
// @lc code=end
