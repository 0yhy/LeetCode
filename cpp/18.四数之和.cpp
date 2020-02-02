/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        // 判重
        map<vector<int>, bool> m;
        sort(nums.begin(), nums.end());
        // 选两个数，后面的数再双指针
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                int num1 = nums[i], num2 = nums[j];
                int start = j + 1, end = nums.size() - 1;
                while (start < end)
                {
                    int sum = num1 + num2 + nums[start] + nums[end];
                    if (sum < target)
                    {
                        int tmp = start;
                        while (tmp == start)
                            ++start;
                    }
                    else if (sum > target)
                    {
                        int tmp = end;
                        while (tmp == end)
                            --end;
                    }
                    else
                    {
                        vector<int> res{num1, num2, nums[start], nums[end]};
                        if (!m[res])
                        {
                            ans.push_back(res);
                            m[res] = true;
                        }
                        ++start;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
