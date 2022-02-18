/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let max = -Infinity,
    ans = 0;
  for (let i = prices.length - 1; i >= 0; --i) {
    max = Math.max(max, prices[i]);
    ans = Math.max(ans, max - prices[i]);
  }
  return ans;
};
