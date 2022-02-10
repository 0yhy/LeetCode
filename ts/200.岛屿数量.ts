/*
 * @lc app=leetcode.cn id=200 lang=typescript
 *
 * [200] 岛屿数量
 */

// @lc code=start
function numIslands(grid: string[][]): number {
  // 并查集做法
  let cnt = 0;

  return cnt;
}

// @lc code=end

// bfs做法
function numIslands(grid: string[][]): number {
  const n = grid.length,
    m = grid[0].length;
  // 初始化vis数组
  const vis: boolean[][] = [];
  for (let i = 0; i < n; ++i) {
    const tmp: boolean[] = [];
    for (let j = 0; j < m; ++j) {
      tmp[j] = false;
    }
    vis.push(tmp);
  }
  // bfs
  function bfs(sx: number, sy: number): void {
    const queue: [number, number][] = [];
    const dir: [number, number][] = [
      [0, -1],
      [0, 1],
      [-1, 0],
      [1, 0],
    ];
    queue.push([sx, sy]);
    while (queue.length) {
      const [sx, sy] = queue.shift() as [number, number];
      for (let i = 0; i < dir.length; ++i) {
        const nx = sx + dir[i][0];
        const ny = sy + dir[i][1];
        if (
          nx >= 0 &&
          nx < n &&
          ny >= 0 &&
          ny < m &&
          grid[nx][ny] === "1" &&
          !vis[nx][ny]
        ) {
          vis[nx][ny] = true;
          queue.push([nx, ny]);
        }
      }
    }
  }
  let cnt = 0;
  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      if (!vis[i][j] && grid[i][j] === "1") {
        bfs(i, j);
        ++cnt;
      }
    }
  }
  return cnt;
}
