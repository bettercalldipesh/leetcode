class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 1: Build Smallest Prime Factor (SPF) sieve
        vector<int> spf(maxVal + 1);

        for(int i = 1; i <= maxVal; i++) {
            spf[i] = i;
        }

        for(int i = 2; i * i <= maxVal; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j <= maxVal; j += i) {
                    if(spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // Step 2: Sliding window
        vector<int> lastSeen(maxVal + 1, -1);

        int left = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            int x = nums[i];

            // Step 3: Factorize current number
            while(x > 1) {
                int p = spf[x];

                // If prime factor was already present
                left = max(left, lastSeen[p] + 1);

                lastSeen[p] = i;

                // Remove repeated occurrences of this prime
                while(x % p == 0) {
                    x /= p;
                }
            }

            // Update maximum pairwise-coprime window
            ans = max(ans, i - left + 1);
        }

        // Any subarray of length 2 satisfies the condition.
        if(n >= 2) return max(ans, 2);

        // A single element satisfies it only when it is 1.
        return nums[0] == 1 ? 1 : 0;
    }
};