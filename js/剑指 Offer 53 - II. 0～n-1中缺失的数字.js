/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
  let l = 0,
    r = nums.length - 1;
  while (l <= r) {
    const m = (l + r) >> 1;
    if (nums[m] === m) l = m + 1;
    else r = m - 1;
  }
  return l;
};
