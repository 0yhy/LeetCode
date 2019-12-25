/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        const long long p_INF = 21474836470;
        const long long n_INF = 21474836480;
        int length = str.size();
        int cnt = 0;
        for (int i = 0; i < length; ++i)
            if (str[i] != ' ')
            {
                cnt = i;
                break;
            }
        if (!isdigit(str[cnt]) && str[cnt] != '+' && str[cnt] != '-')
            return 0;
        long long ans = 0;
        char sign = '+';
        if (!isdigit(str[cnt]))
        {
            sign = str[cnt];
            ++cnt;
        }
        while (isdigit(str[cnt]))
        {
            ans += int(str[cnt++]) - 48;
            ans *= 10;
            if (ans > p_INF && sign == '+')
                return p_INF / 10;
            if (ans > n_INF && sign == '-')
                return n_INF / 10;
        }
        ans /= 10;
        return ans = (sign == '+' ? ans : -ans);
    }
};
// @lc code=end
