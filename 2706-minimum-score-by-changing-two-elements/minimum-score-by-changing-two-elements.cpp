class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        ans = min(ans,nums[n-1] - nums[2]); //Remove 2 smallest elemnets
        ans = min(ans,nums[n-3] - nums[0]); // Remove 2 Largest Elements
        ans = min(ans, nums[n-2] - nums[1]);

        return ans;
    }
};