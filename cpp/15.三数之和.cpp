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
        if (nums.size() < 2)
            return ans;
        map<int, int> m;
        vector<int> negative, positive;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                positive.push_back(nums[i]);
            if (nums[i] < 0)
                negative.push_back(nums[i]);
            ++m[nums[i]];
        }
        if (m[0])
        {
            if (m[0] >= 3)
                ans.push_back(vector<int>{0, 0, 0});
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
