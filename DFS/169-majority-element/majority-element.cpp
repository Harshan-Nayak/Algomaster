class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = floor(n/2);

        sort(nums.begin(),nums.end());

        int i=0;
        int pos;
        int ans;

        while(i<nums.size()){

            auto it1 = lower_bound(nums.begin(),nums.end(),nums[i]);
            auto it2 = upper_bound(nums.begin(),nums.end(),nums[i]);

            if( (it2-nums.begin())-(it1-nums.begin()) > m ){
                pos = i;
                ans = nums[i]; 
            }

            i = (it2-nums.begin());






        }
        
    return ans;
    }
};