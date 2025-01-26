class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int ans;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=1;i<maxi;i++){
            if(binary_search(nums.begin(),nums.end(),i)){
                continue;
            }else{
                ans = i;
                break;
            }
        }
        return ans;
    }
};