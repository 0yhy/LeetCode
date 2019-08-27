/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int num_size = nums.size();
        for(int i = 0; i < num_size; i++)
        {
            for(int j = i + 1; j < num_size; j++)
            {
                if(nums[j] == target - nums[i])
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        } 
        return ans;
    }
};


