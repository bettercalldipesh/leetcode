class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;

        // Coordinate compression
        vector<int> a = nums;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            s[i] = lower_bound(a.begin(), a.end(), nums[i]) - a.begin();
        }

        // Build suffix array using doubling
        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = s[i];
        }

        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j])
                    return rank[i] < rank[j];

                int ri = (i + k < n) ? rank[i + k] : -1;
                int rj = (j + k < n) ? rank[j + k] : -1;

                return ri < rj;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP using Kasai
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        int h = 0;

        for (int i = 0; i < n; i++) {
            if (pos[i] == 0) continue;

            int j = sa[pos[i] - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[pos[i]] = h;

            if (h > 0) h--;
        }

        // Find shortest unique subarray
        int ans = n;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            int maxLCP = 0;

            if (r > 0)
                maxLCP = max(maxLCP, lcp[r]);

            if (r + 1 < n)
                maxLCP = max(maxLCP, lcp[r + 1]);

            int len = maxLCP + 1;

            if (len <= n - i)
                ans = min(ans, len);
        }

        return ans;
    }
};