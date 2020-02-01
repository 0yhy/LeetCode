/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> twoPointer(vector<int> &x, vector<int> &y)
    {
        // 用来判重的map
        map<vector<int>, bool> m;
        vector<vector<int>> ans;
        for (int i = 0; i < x.size(); ++i)
        {
            int start = 0, end = y.size() - 1;
            int cur = -x[i];
            while (start < end)
            {
                int sum = y[start] + y[end];
                if (sum < cur)
                    ++start;
                else if (sum > cur)
                    --end;
                // 找到答案
                else
                {
                    vector<int> res{-cur, y[start], y[end]};
                    sort(res.begin(), res.end());
                    ++start;
                    if (!m[res])
                    {
                        m[res] = true;
                        ans.push_back(res);
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<int>> &threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // 如果数组中的元素小于2个 返回空vector
        if (nums.size() < 2)
            return ans;
        // 记录每个数出现的次数
        map<int, int> m;
        // 负数一组 正数一组
        vector<int> negative, positive;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                positive.push_back(nums[i]);
            if (nums[i] < 0)
                negative.push_back(nums[i]);
            ++m[nums[i]];
        }
        // 如果数组中有0
        if (m[0])
        {
            // 如果0出现了3次及以上 则答案包括了0 0 0
            if (m[0] >= 3)
                ans.push_back(vector<int>{0, 0, 0});
            //如果数组中出现了0，在正数数组中加入0
            positive.push_back(0);
        }
        sort(negative.begin(), negative.end());
        sort(positive.begin(), positive.end());

        vector<vector<int>> ans1 = twoPointer(negative, positive);
        vector<vector<int>> ans2 = twoPointer(positive, negative);
        for (int i = 0; i < ans1.size(); ++i)
            ans.push_back(ans1[i]);
        for (int i = 0; i < ans2.size(); ++i)
            ans.push_back(ans2[i]);
        return ans;
    }
};
// @lc code=end
