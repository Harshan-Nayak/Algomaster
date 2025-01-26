class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int>s(nums.begin(),nums.end());
        vector<int>ans(s.begin(),s.end());
        nums = ans;
        return nums.size();
        
    }
};