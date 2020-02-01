/*
 * @lc app=leetcode.cn id=5296 lang=cpp
 *
 * [5296] 两棵二叉搜索树中的所有元素
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> ans1, ans2;
    void inorder(TreeNode *x, vector<int> &ans)
    {
        if (x == nullptr)
            return;
        else
        {
            inorder(x->left, ans);
            ans.push_back(x->val);
            inorder(x->right, ans);
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        inorder(root1, ans1);
        inorder(root2, ans2);
        vector<int> ans;
        int start1 = 0, end1 = ans1.size();
        int start2 = 0, end2 = ans2.size();
        // for (int i = start1; i < end1; ++i)
        //     cout << ans1[i] << " ";
        // for (int i = start2; i < end2; ++i)
        //     cout << ans2[i] << " ";
        while (start1 < end1 && start2 < end2)
        {
            if (ans1[start1] <= ans2[start2])
            {
                ans.push_back(ans1[start1]);
                ++start1;
            }
            else
            {
                ans.push_back(ans2[start2]);
                ++start2;
            }
        }
        if (start1 < end1)
            for (int i = start1; i < end1; ++i)
                ans.push_back(ans1[i]);
        else if (start2 < end2)
            for (int i = start2; i < end2; ++i)
                ans.push_back(ans2[i]);
        return ans;
    }
};
// @lc code=end
