class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> num_set(nums.begin() ,nums.end());

        if(num_set.size() != nums.size()) return true;




        return false;
    }
};