class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;

        //To find the Breakpoint 
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                breakpoint = i;
                break;
            }
        }

        if(breakpoint == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // Next Smallest Greater Element
        int pos = -1;
        for(int i=n-1; i>breakpoint; i--){
            if(nums[i] > nums[breakpoint]){
                pos = i;
                break;
            }   
        }
        swap(nums[pos],nums[breakpoint]);

        reverse(nums.begin() + breakpoint + 1, nums.end());
    }
};