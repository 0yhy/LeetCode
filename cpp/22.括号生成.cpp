/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
    vector<string> ans;

public:
    vector<string> generateParenthesis(int n)
    {
        dfs("", n, 0, 0);
        return ans;
    }
    bool isParenthesisCorrect(string parenStr)
    {
        stack<char> s;
        for (int i = 0; i < parenStr.size(); ++i)
        {
            if (parenStr[i] == '(')
                s.push(')');
            else
            {
                if (s.empty() || parenStr[i] != s.top())
                    return false;
                else
                    s.pop();
            }
        }
        return !s.size();
    }
    void dfs(string curstr, int n, int l_num, int r_num)
    {
        if (curstr.size() == n * 2)
        {
            if (isParenthesisCorrect(curstr))
                ans.push_back(curstr);
            return;
        }
        if (l_num < n)
            dfs(curstr + "(", n, l_num + 1, r_num);
        if (r_num < n)
            dfs(curstr + ")", n, l_num, r_num + 1);
        return;
    }
};
// @lc code=end
