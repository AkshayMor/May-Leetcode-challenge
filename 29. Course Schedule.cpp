class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
         vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto req : prerequisites){
            G[req[1]].push_back(req[0]); 
            degree[req[0]]++;
        }
        for (int i = 0; i < n; ++i)
            if (!degree[i])
                bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0)
                    bfs.push_back(j);
        return bfs.size() == n;
    }
};