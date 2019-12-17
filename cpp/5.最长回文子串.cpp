/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = s.size();
        for (int i = length; i >= 1; --i) // 枚举字串长度
        {
            for (int j = 0; j <= length - i; ++j)
            {
                if (isPalindrome(j, i, s))
                    return s.substr(j, i);
            }
        }
        return "";
    }
    bool isPalindrome(int start, int length, string &s)
    {
        for (int i = start; i < start + (length + 1) / 2; ++i)
            if (s[i] != s[2 * start + length - i - 1])
                return false;
        return true;
    }
};
// @lc code=end
