class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans ;
        sort(nums.begin() ,nums.end());

        findAllSub(nums , ans ,{} ,0);
        sort(ans.begin() , ans.end());

        ans.erase(unique(ans.begin() , ans.end()) , ans.end());
        


        return ans;


    }

    void findAllSub(vector<int> nums , vector<vector<int>>& ans , vector<int> sub ,int next){

        if(next == nums.size()){
            ans.push_back(sub);
            return;
        }

        findAllSub(nums , ans , sub , next+1);
        sub.push_back(nums[next]);
        findAllSub(nums ,ans , sub , next+1);

    }
};