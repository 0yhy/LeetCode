/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        auto len = s.size();
        string sub = "";
        int ans = 0;
        for (auto i = 0; i < len; ++i)
        {
            int index = sub.find(s[i]);
            if (index != string::npos)
            {
                sub = sub.erase(0, index + 1);
            }
            sub += s[i];
            // cout << "sub:" << sub << endl;
            ans = max(ans, int(sub.size()));
        }
        return ans;
    }
};
// @lc code=end
