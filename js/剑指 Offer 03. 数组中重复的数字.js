/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function (nums) {
  let i = 0;
  while (i < nums.length) {
    const m = nums[i];
    if (m === i) ++i;
    else {
      if (m === nums[m]) return nums[m];
      else {
        nums[i] = nums[m];
        nums[m] = m;
      }
    }
  }
  return -1;
};
