class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n = items.size();

        vector<int> reward(n, 0);

        // Calculate free rewards for each item type
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    reward[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];
            int bonus = reward[i];

            vector<int> ndp = dp;

            // For each residue modulo price
            for (int r = 0; r < price && r <= budget; r++) {
                int best = INT_MIN;
                
                for (int b = r; b <= budget; b += price) {
                    int t = (b - r) / price;

                    // We need at least one copy to activate the bonus
                    if (t >= 1) {
                        int prevIndex = b - price;
                        
                        // dp[prevIndex] + bonus + 1
                        ndp[b] = max(ndp[b], dp[prevIndex] + bonus + 1);
                    }

                    // Additional copies of this item
                    if (b >= price) {
                        ndp[b] = max(ndp[b], ndp[b - price] + 1);
                    }
                }
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};