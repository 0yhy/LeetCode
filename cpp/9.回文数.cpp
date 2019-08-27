/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // solution 1
        // if(x < 0)
        //     return false;
        // else if(x < 10)
        //     return true;

        // const int MAXN = 10;
        // int nums[MAXN];
        // for(int i = 0; i < MAXN; i++)
        //     nums[i]  = 0;

        // int cnt = 0;
        // bool flag = true;
        
        // while(x != 0)
        // {
        //     nums[cnt++] = x % 10;
        //     x /= 10;
        // }
        // for(int i = 0; i <= cnt / 2; i++)
        //     if(nums[i] != nums[cnt - i - 1])
        //     {
        //         flag = false;
        //         break;
        //     }
        // return flag;


        //solution 2
        int pre = x;
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
        
        long long reverse = 0;
        while(x != 0)
        {
            reverse *= 10;
            reverse += (x % 10);
            x /= 10;
        }
        if(pre == reverse)
            return true;
        else 
            return false;
    }
};

