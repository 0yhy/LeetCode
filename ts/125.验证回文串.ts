/*
 * @lc app=leetcode.cn id=125 lang=typescript
 *
 * [125] 验证回文串
 */

// @lc code=start
function isPalindrome(s: string): boolean {
  let l = 0,
    r = s.length - 1;
  const isValid = (char): boolean => {
    const code = char.charCodeAt();
    return (
      (code >= 97 && code <= 122) ||
      (code >= 65 && code <= 90) ||
      (code >= 48 && code <= 57)
    );
  };
  while (l < r && !isValid(s[l])) ++l;
  while (l < r && !isValid(s[r])) --r;
  while (l <= r) {
    if (s[l].toUpperCase() === s[r].toUpperCase()) {
      ++l, --r;
      while (l < r && !isValid(s[l])) ++l;
      while (l < r && !isValid(s[r])) --r;
    } else return false;
  }
  return true;
}
// @lc code=end
