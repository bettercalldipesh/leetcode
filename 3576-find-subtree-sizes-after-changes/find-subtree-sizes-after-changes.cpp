class Solution {
public:

    vector<vector<int>> adj;
    vector<vector<int>> newAdj;

    vector<int> newParent;
    vector<int> ans;

    int last[26];

    void dfs1(int node, string &s) {

        int ch = s[node] - 'a';

        int prev = last[ch];

        // Find the closest ancestor with same character
        if(prev != -1) {
            newParent[node] = prev;
        }

        // Update the latest occurrence
        last[ch] = node;

        // Explore children
        for(auto child : adj[node]) {
            dfs1(child, s);
        }

        // Restore previous occurrence
        last[ch] = prev;
    }

    int dfs2(int node) {

        ans[node] = 1;

        for(auto child : newAdj[node]) {
            ans[node] += dfs2(child);
        }

        return ans[node];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        newAdj.resize(n);

        newParent = parent;
        ans.resize(n, 0);

        // Build original tree
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Initialize last array
        fill(last, last + 26, -1);

        // Find new parents
        dfs1(0, s);

        // Build modified tree
        for(int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        dfs2(0);

        return ans;
    }
};