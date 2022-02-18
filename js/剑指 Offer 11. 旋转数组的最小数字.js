/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function (numbers) {
  let l = 0,
    r = numbers.length - 1;
  while (l < r) {
    const m = (l + r) >> 1;
    if (numbers[m] > numbers[r]) l = m + 1;
    else if (numbers[m] < numbers[r]) r = m;
    else --r;
  }
  return numbers[l];
};
console.log(minArray([3, 3, 1, 3]));
