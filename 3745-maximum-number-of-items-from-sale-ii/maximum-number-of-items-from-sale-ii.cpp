class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        for (auto& item : items)
            freq[item[0]]++;

        // Count all item types whose factors are multiples of f
        vector<int> divisibleCount(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int multiple = f; multiple <= n; multiple += f) {
                divisibleCount[f] += freq[multiple];
            }
        }

        // Calculate gain for each individual item
        vector<pair<int, int>> boosted;

        int minPrice = INT_MAX;

        for (auto& item : items)
            minPrice = min(minPrice, item[1]);

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            // Exclude the current item itself
            int gain = divisibleCount[factor] - 1;

            // At most gain purchases can produce bonus copies
            if (gain > 0 && price <= 2LL * minPrice) {
                boosted.push_back({price, gain});
            }
        }

        sort(boosted.begin(), boosted.end());

        long long ans = 0;
        long long remaining = budget;

        // Buy the cheapest boosted copies first
        for (auto& [price, count] : boosted) {
            long long canBuy = remaining / price;
            long long take = min(canBuy, (long long)count);

            ans += 2LL * take;
            remaining -= take * price;
        }

        // Spend remaining budget on cheapest regular copies
        ans += remaining / minPrice;

        return ans;

    }
};