/*
 * @lc app=leetcode.cn id=174 lang=typescript
 *
 * [174] 地下城游戏
 */

// @lc code=start
function calculateMinimumHP(dungeon: number[][]): number {
  const m = dungeon.length,
    n = dungeon[0].length;
  const minHP: number[][] = [];
  for (let i = 0; i <= m; ++i) {
    const tmp = [];
    for (let j = 0; j <= n; ++j) {
      tmp.push(Infinity);
    }
    minHP.push([...tmp]);
  }
  (minHP[m][n - 1] = 1), (minHP[m - 1][n] = 1);
  for (let i = m - 1; i >= 0; --i) {
    for (let j = n - 1; j >= 0; --j) {
      minHP[i][j] = Math.max(
        Math.min(minHP[i][j + 1], minHP[i + 1][j]) - dungeon[i][j],
        1
      );
    }
  }
  return minHP[0][0];
}
// @lc code=end
