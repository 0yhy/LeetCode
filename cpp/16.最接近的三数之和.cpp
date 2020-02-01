/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cur = nums[i];
            int start = i + 1, end = nums.size() - 1;
            while (start < end)
            {
                int sum = cur + nums[start] + nums[end];
                if (sum < target)
                    ++start;
                else if (sum > target)
                    --end;
                else
                    return target;
                if (abs(target - sum) < abs(target - ans))
                    ans = sum;
            }
        }
        return ans;
    }
};
// @lc code=end
