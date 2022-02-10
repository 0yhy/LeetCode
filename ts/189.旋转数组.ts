/*
 * @lc app=leetcode.cn id=189 lang=typescript
 *
 * [189] 旋转数组
 */

// @lc code=start
/**
 Do not return anything, modify nums in-place instead.
 */
function rotate(nums: number[], k: number): void {
  k = k % nums.length;
  function reverse(nums: number[], l: number, r: number) {
    while (l < r) {
      const tmp = nums[l];
      nums[l] = nums[r];
      nums[r] = tmp;
      ++l, --r;
    }
  }
  reverse(nums, nums.length - k, nums.length - 1);
  reverse(nums, 0, nums.length - 1);
  reverse(nums, k, nums.length - 1);
}
// @lc code=end
