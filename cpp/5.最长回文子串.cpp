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
        const int MAXN = 1001;
        bool isPalin[MAXN][MAXN] = {0};
        int length = s.size();
        for (int i = 0; i < length; ++i)
            isPalin[i][i] = true;
        for (int i = 0; i < length - 1; ++i)
        {
            if (s[i] == s[i + 1])
                isPalin[i][i + 1] = true;
        }
        for (int i = 2; i < length; ++i) // i是坐标差
        {
            for (int j = 0; j < length - i; ++j)
                if (s[j] == s[j + i] && isPalin[j + 1][j + i - 1])
                    isPalin[j][j + i] = true;
        }
        for (int i = length - 1; i >= 0; --i) // i是坐标差
            for (int j = 0; j < length - i; ++j)
                if (isPalin[j][j + i])
                    return s.substr(j, i + 1);
        return "";
    }

    string longestPalindrome1(string s)
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
