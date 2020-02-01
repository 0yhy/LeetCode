/*
 * @lc app=leetcode.cn id=5295 lang=cpp
 *
 * [5295] 和为零的N个唯一整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        int cnt = n / 2;
        vector<int> ans;
        for (int i = 1; i <= cnt; ++i)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1)
            ans.push_back(0);
        return ans;
    }
};
// @lc code=end
