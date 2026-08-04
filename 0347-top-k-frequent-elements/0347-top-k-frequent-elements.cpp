class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket short

        unordered_map<int,int> mp;

        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++; // 
        }

        //bucket array
        vector<vector<int>> bucket(nums.size()+1);  //[[]] here index->freq and [...[num with frequency == index i]]

        for( auto it : mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        
        for(int i = nums.size() ; i>0 ;i--){
            for(int a : bucket[i]){
                
            ans.push_back(a);

            if(ans.size() == k) return ans;

            }
        }

        return ans;
        

    }
};