/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
  const MOD = 1e9 + 7;
  if (!n) return 0;
  let a = 0,
    b = 0,
    c = 1;
  for (let i = 0; i < n - 1; ++i) {
    let t = (b + c) % MOD;
    a = b;
    b = c;
    c = t;
  }
  return c;
};
