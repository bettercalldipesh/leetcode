class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
       unordered_map<int,int> mpp;

       for(int i=0; i<n; i++){
        mpp[nums[i]]++;
       }

       int maxcnt = 0;
       int ans = -1;

       for(auto it: mpp){
            if(it.second > maxcnt){
                maxcnt = it.second;
                ans = it.first;
            }
       }

       return ans;
    }
};