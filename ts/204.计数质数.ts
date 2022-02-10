/*
 * @lc app=leetcode.cn id=204 lang=typescript
 *
 * [204] 计数质数
 */

// @lc code=start
function countPrimes(n: number): number {
  const isPrime: boolean[] = new Array(n).fill(true);
  const primes: number[] = [];
  for (let i = 2; i < n; ++i) {
    if (isPrime[i]) {
      primes.push(i);
    }
    for (let j = 0; j < primes.length && i * primes[j] < n; ++j) {
      isPrime[i * primes[j]] = false;
      if (i % primes[j] === 0) break;
    }
  }
  return primes.length;
}
// @lc code=end
