/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int head = 0, tail = height.size() - 1;
        int ans = 0;
        while (head < tail)
        {
            ans = max(ans, (tail - head) * min(height[head], height[tail]));
            if (height[head] < height[tail])
                ++head;
            else
                --tail;
        }
        return ans;
    }
    int maxAreaBruteForce(vector<int> &height) //49/50
    {
        int cnt = height.size();
        int ans = 0;
        for (int i = 0; i < cnt; ++i)
        {
            for (int j = i + 1; j < cnt; ++j)
                ans = max(ans, (j - i) * min(height[i], height[j]));
        }
        return ans;
    }
};
// @lc code=end
