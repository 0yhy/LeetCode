/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function (matrix, target) {
  if (!matrix.length || !matrix[0].length) return false;
  const n = matrix.length - 1,
    m = matrix[0].length - 1;
  let i = 0,
    j = m;
  while (i <= n && j >= 0 && matrix[i][j] !== target) {
    if (matrix[i][j] < target) ++i;
    else if (matrix[i][j] > target) --j;
    console.log(i, j);
  }
  return i <= n && j >= 0 && matrix[i][j] === target;
};
