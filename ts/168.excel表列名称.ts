/*
 * @lc app=leetcode.cn id=168 lang=typescript
 *
 * [168] Excel表列名称
 */

// @lc code=start
function convertToTitle(columnNumber: number): string {
  let ans: string = "";
  const numbToAlpha = (num: number) =>
    String.fromCharCode(num + "A".charCodeAt(0));
  while (columnNumber) {
    --columnNumber;
    ans = `${numbToAlpha(columnNumber % 26)}${ans}`;
    columnNumber = Math.floor(columnNumber / 26);
  }
  return ans;
}
// @lc code=end
