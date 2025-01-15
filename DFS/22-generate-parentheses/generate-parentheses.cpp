class Solution {
public:
void backtrack(int open,int close, vector<string>&res,string s,int n){
    if(s.length()==2*n){
        res.push_back(s);
        return ;
    }
    if(open<n){
        backtrack(open+1,close,res,s + "(" ,n);
    }

    if(close<open){
        backtrack(open,close+1,res,s+")",n);
    }






}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s ="";
        backtrack(0,0,res,s,n);




        return res;
        
    }
};