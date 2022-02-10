/*
 * @lc app=leetcode.cn id=121 lang=typescript
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
function maxProfit(prices: number[]): number {
  let ans = 0,
    curMax = prices[prices.length - 1];
  for (let i = prices.length - 2; i >= 0; --i) {
    ans = Math.max(ans, curMax - prices[i]);
    curMax = Math.max(curMax, prices[i]);
  }
  return ans;
}
// @lc code=end
