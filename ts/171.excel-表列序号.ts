/*
 * @lc app=leetcode.cn id=171 lang=typescript
 *
 * [171] Excel 表列序号
 */

// @lc code=start
function titleToNumber(columnTitle: string): number {
  let ans = 0,
    pow = 0;
  for (let i = columnTitle.length - 1; i >= 0; --i) {
    ans +=
      Math.pow(26, pow++) *
      (columnTitle[i].charCodeAt(0) - "A".charCodeAt(0) + 1);
  }
  return ans;
}
// @lc code=end
