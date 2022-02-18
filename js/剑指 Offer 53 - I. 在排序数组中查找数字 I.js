/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  function binarySearch(l, r, lower) {
    while (l < r) {
      if (lower) {
        const m = (l + r) >> 1;
        if (nums[m] >= target) r = m;
        else l = m + 1;
      } else {
        const m = ((l + r) >> 1) + 1;
        if (nums[m] > target) r = m - 1;
        else l = m;
      }
    }
    return nums[l] !== target ? (lower ? 0 : -1) : l;
  }
  const left = binarySearch(0, nums.length - 1, true);
  const right = binarySearch(0, nums.length - 1, false);
  return right - left + 1;
};
