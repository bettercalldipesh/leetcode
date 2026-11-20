class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int cnt=0;
        int candidate = nums[i];

        while(i<n){
            if(cnt == 0){
                candidate = nums[i];
            }

            if(nums[i] == candidate){
                cnt++;
            }
            else {
                cnt--;
            }
            i++;
        }

        return candidate;
    }
};