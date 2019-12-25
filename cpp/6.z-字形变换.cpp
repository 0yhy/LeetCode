/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        const int MAXN = 2005;
        int length = s.size();
        string ans[MAXN];
        int row = 0;
        bool direction = false; //true往下走
        for (int i = 0; i < length; ++i)
        {
            ans[row] += s[i];
            if (row == numRows - 1 || row == 0)
                direction = !direction;
            if (direction)
                ++row;
            else
                --row;
        }
        string res;
        for (int i = 0; i <= numRows; ++i)
            res += ans[i];
        return res;
    }
    string convertBruteForce(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        const int MAXN = 705;
        int z[MAXN][MAXN] = {0};
        int length = s.size();
        string direction = "down";
        int x = 0, y = 0;
        z[x][y] = 0;
        for (int i = 0; i < length; ++i)
        {
            z[x][y] = i;
            // cout << x << " " << y << endl;
            if (x == numRows - 1)
                direction = "right";
            if (x == 0)
                direction = "down";
            if (direction == "down")
                ++x;
            if (direction == "right")
            {
                --x;
                ++y;
            }
        }
        string ans = s.substr(0, 1);
        for (int i = 0; i < numRows; ++i)
            for (int j = 0; j <= y; ++j)
                if (z[i][j])
                    ans += s[z[i][j]];
        return ans;
    }
};
// @lc code=end
