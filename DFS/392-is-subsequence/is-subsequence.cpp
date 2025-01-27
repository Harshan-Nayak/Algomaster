class Solution {
public:
    bool isSubsequence(string s, string t) {

        string str = "";
        int j =0;


        for(int i=0;i<t.length();i++){
            if(s[j]==t[i]){
                str += s[j];
                j++; 
            }
        }
        if(str==s){
            return true;
        }else{
            return false;
        }
    }
};