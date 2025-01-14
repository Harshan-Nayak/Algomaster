class Solution {
public:


bool isFeasible(vector<int>& weights, int days,int mid){
    int ctDays = 1;
    int sum =0;
    for(auto wt:weights){
        sum += wt;
        if(sum>mid){
            ctDays++;
            sum=wt;
        }
    }
 return ctDays <= days; 

}


    int shipWithinDays(vector<int>& weights, int days) {
      int low = *max_element(weights.begin(), weights.end());

        int high = accumulate(weights.begin(),weights.end(),0);
        int result = high;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(isFeasible(weights,days,mid)){
                result = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return result;
        
    }
};