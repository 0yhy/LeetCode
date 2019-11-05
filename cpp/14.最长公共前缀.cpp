/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = "";
        int min_length = 2147482647;
        int num = strs.size();
        for(int i = 0; i < num; i++)
            if(min_length > strs[i].length()) 
                min_length = strs[i].length();
        for(int i = 0; i < min_length; i++)
        {
            bool flag = true;
            for(int j = 1; j < num; j++)
            {
                if(strs[j - 1][i] != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans += strs[0][i];
            else 
                break;
        }
        return ans;
    }
};

