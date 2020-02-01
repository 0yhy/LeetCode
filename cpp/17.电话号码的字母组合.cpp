/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
    vector<string> ans;
    string strs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string digits;

public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return ans;
        this->digits = digits;
        recursive("", 0);
        return ans;
    }
    void recursive(string curStr, int curIndex)
    {
        if (curStr.size() == this->digits.size())
        {
            ans.push_back(curStr);
            return;
        }
        int curNum = int(this->digits[curIndex]) - 48;
        for (auto ch : strs[curNum])
        {
            recursive(curStr + ch, curIndex + 1);
        }
        return;
    }
};
// @lc code=end
