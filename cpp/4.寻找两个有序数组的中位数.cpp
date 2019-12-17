/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int tail1 = nums1.size(), tail2 = nums2.size();
        int cnt = (tail1 + tail2) / 2;
        int front1 = 0, front2 = 0;
        int INF = 0x3f3f3f3f;
        while (cnt)
        {
            int v1 = INF, v2 = INF;
            if (front1 <= tail1)
            {
                v1 = nums1[front1 + min((tail1 - front1), cnt) - 1];
            }
            if (front2 <= tail2)
            {
                v2 = nums2[front2 + min((tail2 - front2), cnt) - 1];
            }
            cout << v1 << " " << v2 << endl;
            if (v1 <= v2)
                front1 += min((tail1 - front1), cnt);
            else
                front2 += min((tail2 - front2), cnt);
            cnt /= 2;
        }
        int a1 = max(nums1[front1 - 1], nums2[front2 - 1]);
        int a2 = min(nums1[front1], nums2[front2]);
        if ((tail1 + tail2) % 2 == 1)
            return a1;
        else
            return double(a1 + a2) / 2;
    }

    double findMedianSortedArraysBruteForce(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merge;
        const int INF = 0x3f3f3f3f;
        int front1 = 0, front2 = 0;
        int tail1 = nums1.size(), tail2 = nums2.size();
        while (front1 != tail1 || front2 != tail2)
        {
            int v1 = INF, v2 = INF;
            if (front1 != tail1)
                v1 = nums1[front1];
            if (front2 != tail2)
                v2 = nums2[front2];
            if (v1 <= v2)
            {
                merge.push_back(v1);
                ++front1;
            }
            else
            {
                merge.push_back(v2);
                ++front2;
            }
        }
        if (merge.size() % 2 == 1)
            return merge[merge.size() / 2];
        else
            return (double(merge[merge.size() / 2 - 1] + merge[merge.size() / 2])) / 2;
    }
};
// @lc code=end
