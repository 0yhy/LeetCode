/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int y) {
        long long x = y;
        const int INF = 2147483647;
        const int MAXN = 10;
        int cnt = 0, beg = 0;
        long long ans = 0;
        int saveNum[MAXN];
        for(int i = 0; i < MAXN; i++)
            saveNum[i] = 0;

        long long num = abs(x);
        if(num == 0) return 0;
        while(num)
        {
            saveNum[cnt++] = num % 10;
            num /= 10;
        }
        while(saveNum[beg] == 0)
            beg++;
        for(int i = beg; i < cnt; i++)
        {
            ans *= 10;
            
            ans += saveNum[i];
        }
        if(x < 0)
        {
            if(ans / (INF + 1) != 0) return 0;
            else return -ans;
        }
        else 
        {
            if(ans / INF != 0) return 0;
            else return ans;
        }
    }
};

