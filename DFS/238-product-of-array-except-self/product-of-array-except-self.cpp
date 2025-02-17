class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        reverse(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            suffix[i]=suffix[i-1]*nums[i-1];
        }
        reverse(suffix.begin(),suffix.end());
        vector<int>ans;

        for(int i=0;i<prefix.size();i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};