class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        

        sort(candidates.begin() , candidates.end());

        vector<vector<int>> ans ;
        vector<int> sub;

        solve(candidates,ans,sub,target,0);
        return ans;
        
    }

    void solve(vector<int> &nums , vector<vector<int>> &ans , vector<int> &sub , int target ,int  start){

        if(target == 0){
            ans.push_back(sub);
            return;
        }

        for(int i = start ; i<nums.size() ; i++){

            if(target - nums[i] < 0 ) return;
            if( i > start && nums[i] == nums[i-1]) continue;

            
            sub.push_back(nums[i]);
            solve(nums,ans,sub,target-nums[i],i+1);

            sub.pop_back();

        }

        return;
    }
};