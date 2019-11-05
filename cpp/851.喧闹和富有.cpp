/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int MAXN = 1000;
        vector<int> answer;
        vector<int> e[MAXN];
        int edge_num = 0;
        int richer_size = richer.size();
        for(int i = 0; i < richer_size; i++)
        {
            e[richer[i][0]].push_back(richer[i][1]);
            edge_num ++;
        }

        for(int i = 0; i < edge_num; i++)
        {
            int ans = 2147483647;
            queue<int> q;
            bool inq[MAXN] = {0};
            q.push(i);
            inq[i] = true;
            while(!q.empty())
            {
                int now = q.front();
                q.pop();
                inq[now] = false;
                for(int i = 0; i < e[now].size(); i++)
                {
                    int next = e[now][i];
                    if(quiet[next] < ans)
                    {
                        ans = quiet[next];
                        if(!inq[next])
                        {
                            inq[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
            answer.push_back(ans);
            ans = 2147483647;
            for(int i = 0; i < MAXN; i++)
                inq[i] = 0;
        }
        return answer;
    }
};
// @lc code=end

