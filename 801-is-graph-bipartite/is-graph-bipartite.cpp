class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        queue<int> q;

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : graph[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        }
                        // is Adjacent guy having the same color? if it has same
                        // therefore someone had colored it before
                        else if (color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};