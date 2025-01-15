class Solution {
public:
void backtrack( vector<vector<int>>&res, vector<int>&path,int start,vector<int>& nums){

    res.push_back(path);


    for(int i=start;i<nums.size();i++){
        path.push_back(nums[i]);
        backtrack(res,path,i+1,nums);
        path.pop_back();
    }



 }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        backtrack(res,path,0,nums);

        return res;
        
    }
};