/*
 * @lc app=leetcode.cn id=153 lang=typescript
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
function findMin(nums: number[]): number {
  if (nums.length === 1) return nums[0];
  function binary(l: number, r: number) {
    const mid = Math.floor((l + r) / 2);
    if (nums[mid + 1] > nums[r]) return binary(mid, r);
    else if (nums[mid] < nums[l]) return binary(l, mid);
    else return Math.min(nums[l], nums[mid + 1]);
  }
  return binary(0, nums.length - 1);
}
// @lc code=end
