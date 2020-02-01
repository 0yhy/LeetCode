/*
 * @lc app=leetcode.cn id=5297 lang=cpp
 *
 * [5297] 跳跃游戏 III
 */

// @lc code=start
class Solution
{
public:
    bool isVisit[50005] = {0};
    bool canReach(vector<int> &arr, int start)
    {
        if (arr[start] == 0)
            return true;
        else
        {
            int left = start - arr[start];
            int right = start + arr[start];
            bool res = false;
            if (left >= 0 && !isVisit[left])
            {
                isVisit[left] = true;
                res = res || canReach(arr, left);
            }

            if (right < arr.size() && !isVisit[right])
            {
                isVisit[right] = true;
                res = res || canReach(arr, right);
            }
            return res;
        }
    }
};
// @lc code=end
