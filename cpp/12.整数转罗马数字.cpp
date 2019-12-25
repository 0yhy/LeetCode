/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = intToRomanRecursive(num, "");
        return ans;
    }
    string intToRomanRecursive(int num, string ans)
    {
        if (num == 0)
            return ans;
        if (num >= 1000)
            return intToRomanRecursive(num - 1000, ans + "M");
        else if (num >= 900)
            return intToRomanRecursive(num - 900, ans + "CM");
        else if (num >= 500)
            return intToRomanRecursive(num - 500, ans += "D");
        else if (num >= 400)
            return intToRomanRecursive(num - 400, ans + "CD");
        else if (num >= 100)
            return intToRomanRecursive(num - 100, ans += "C");
        else if (num >= 90)
            return intToRomanRecursive(num - 90, ans + "XC");
        else if (num >= 50)
            return intToRomanRecursive(num - 50, ans += "L");
        else if (num >= 40)
            return intToRomanRecursive(num - 40, ans + "XL");
        else if (num >= 10)
            return intToRomanRecursive(num - 10, ans += "X");
        else if (num >= 9)
            return intToRomanRecursive(num - 9, ans + "IX");
        else if (num >= 5)
            return intToRomanRecursive(num - 5, ans += "V");
        else if (num >= 4)
            return intToRomanRecursive(num - 4, ans += "IV");
        else if (num >= 1)
            return intToRomanRecursive(num - 1, ans += "I");
        else
            return "";
    }
};
// @lc code=end
