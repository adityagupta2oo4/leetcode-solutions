class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans ;
        vector<int> sub;
        solve(candidates , ans , sub, target ,0);

        return ans;
   
    }

    void solve(vector<int> &nums , vector<vector<int>> &ans , vector<int> &sub , int target , int start){

        if(target == 0) {
            ans.push_back(sub);
            return;
        }
       
        
        for(int i = start ; i<nums.size() ; i++){

            if(target - nums[i] < 0) continue;

            sub.push_back(nums[i]);

            solve(nums,ans,sub,target-nums[i] ,i);

            sub.pop_back();

        }



        return ;
    }
};