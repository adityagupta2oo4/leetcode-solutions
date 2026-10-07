class Solution {
public:

    void per(vector<vector<int>> &ans,vector<int> nums , vector<int> &cur , vector<bool> &used){

        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return ;
        }

        for(int i =0 ; i<nums.size() ; i++){
            
            if(used[i]) continue;

            cur.push_back(nums[i]);
            used[i] = true;
            per(ans,nums,cur,used);

            // back tracking
            cur.pop_back();
            used[i] = false;
        }

        return ;
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(),false);
        per(ans,nums,cur,used);

        
        return ans;
    }
};

