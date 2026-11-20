class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int mxcnt = 0;

        for(auto num : st){
            if(st.find(num-1) == st.end()){
                int cnt = 1;
                int x = num;

                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                }

                mxcnt = max(cnt,mxcnt);
            }
        }
        return mxcnt;
    }
};