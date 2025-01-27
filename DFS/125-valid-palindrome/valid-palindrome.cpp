class Solution {
public:
    bool isPalindrome(string s) {

        string str ="";

        for(auto it:s){
            if(isalnum(it)){
                str += tolower(it);
            }
        }

        string rev = str;
        reverse(rev.begin(),rev.end());
        if(rev==str){
            return true;
        }else{
            return false;
        }
        
    }
};