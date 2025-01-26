class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int ct = 0;
        for(auto &it:nums){
            if(it==0){
                ct++;
            }
        }

        for(int i=0;i<ct;i++){
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j]==0){
                    swap(nums[j],nums[j+1]);
                    
                }
            }
        }
        
    }
};