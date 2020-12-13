/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> curDis = {0};
    void dfs(int cur, vector<vector<int>> &graph)
    {
        int lastPos = graph.size() - 1;
        if (cur == lastPos)
        {
            ans.push_back(curDis);
            return;
        }
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            curDis.push_back(graph[cur][i]);
            dfs(graph[cur][i], graph);
            curDis.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(0, graph);
        return ans;
    }
};
// @lc code=end
