/*
 * @lc app=leetcode.cn id=162 lang=typescript
 *
 * [162] 寻找峰值
 */

// @lc code=start
function findPeakElement(nums: number[]): number {
  function binary(l: number, r: number) {
    const mid = Math.floor((l + r) / 2);
    if (nums[mid] <= nums[mid - 1]) return binary(l, mid - 1);
    else if (nums[mid] <= nums[mid + 1]) return binary(mid + 1, r);
    else return mid;
  }
  return binary(0, nums.length - 1);
}
// @lc code=end
