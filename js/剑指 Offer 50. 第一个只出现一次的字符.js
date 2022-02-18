/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function (s) {
  const LEN = 26;
  const map = new Array(LEN).fill(0);
  const index = (c) => c.charCodeAt() - "a".charCodeAt();
  for (const c of s) {
    ++map[index(c)];
  }
  for (const c of s) {
    if (map[index(c)] === 1) {
      return c;
    }
  }
  return " ";
};
console.log(firstUniqChar("leetcode"));
