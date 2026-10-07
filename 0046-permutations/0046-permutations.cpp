class Solution {
public:

    void per(vector<vector<int>> &ans,vector<int> nums , vector<int> &cur , int len){

        if(cur.size() == len){
            ans.push_back(cur);
            return ;
        }

        for(int i =0 ; i<nums.size() ; i++){
            int rem = nums[i];
            cur.push_back(rem);
            nums.erase(nums.begin()+i);
            per(ans,nums,cur,len);

            // back tracking
            cur.pop_back();
            // restoring the nums
            nums.insert(nums.begin() + i ,rem);
        }

        return ;
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> cur;

        per(ans,nums,cur,nums.size());

        
        return ans;
    }
};

