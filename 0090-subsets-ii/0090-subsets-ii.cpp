class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> sub;

        solve(nums, ans, sub, 0);

        return ans;
    }

    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& sub,
               int start) {

        ans.push_back(sub);

        for(int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if(i > start && nums[i] == nums[i - 1])
                continue;

            sub.push_back(nums[i]);

            solve(nums, ans, sub, i + 1);

            sub.pop_back();
        }
    }
};