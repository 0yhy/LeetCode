/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int sum = 0;

    int num_size = s.size();
    for(int i = 0; i < num_size; i++)
    {
        if(m[s[i]] < m[s[i + 1]])
            sum -= m[s[i]];
        else
            sum += m[s[i]];
    }
    return sum;
    }
};

