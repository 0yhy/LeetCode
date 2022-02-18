/**
 * @param {number} n
 * @return {number}
 */
var numWays = function (n) {
  const MOD = 1e9 + 7;
  let a = 0,
    b = 0,
    c = 1;
  for (let i = 0; i < n; ++i) {
    let t = (b + c) % MOD;
    a = b;
    b = c;
    c = t;
  }
  return c;
};
