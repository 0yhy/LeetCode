/*
 * @lc app=leetcode.cn id=165 lang=typescript
 *
 * [165] 比较版本号
 */

// @lc code=start
function compareVersion(version1: string, version2: string): number {
  let flag = true;
  let ans = 0;
  let [a, b]: string[][] = [version1.split("."), version2.split(".")];
  if (a.length > b.length) {
    [a, b] = [b, a];
    flag = false;
  }
  let t = b.length - a.length;
  while (t--) {
    a.push("0");
  }
  for (let i = 0; i < a.length; ++i) {
    const v1 = Number(a[i]),
      v2 = Number(b[i]);
    if (v1 > v2) {
      ans = flag ? 1 : -1;
      break;
    } else if (v1 < v2) {
      ans = flag ? -1 : 1;
      break;
    }
  }
  return ans;
}
// @lc code=end
