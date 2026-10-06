class Solution {
public:

    bool ispalindrom(string x){
        
        if(x.length() == 0) return false;

        for(int i = 0 ; i<x.length() ; i++){
            if(x[i] != x[x.length()-i-1]) return false;
        }

        return true;

    }

    void subString(string s,int start, vector<vector<string>> &ans,vector<string> cur){

        if(start == s.length()){
            if(!cur.empty()) ans.push_back(cur);
            return;
        };

        

        for(int end = start ; end<s.length() ; end++ ){

            if(ispalindrom(s.substr(start,end-start+1))){
                cur.push_back(s.substr(start,end-start+1));

                subString(s,end+1,ans,cur);
                cur.pop_back();
            }

        }

        
        
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;

        vector<string> cur;

        
        subString(s,0,ans,cur);

        return ans;

        

        
    }
};