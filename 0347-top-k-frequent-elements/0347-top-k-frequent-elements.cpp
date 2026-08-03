class Solution {
public:

    int maxByValue(map<int,int>  &mp){ // passing by reference so that we do have to copy the hash map for each function call

        int key_max = 0; // assigning zero so that no garbage value
        int value_max = INT_MIN;

        for(auto it : mp){
            if(it.second>value_max) {
                value_max = it.second;
                key_max = it.first;
            }
        }
        return key_max;

    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> hashMap;
        
        for(int i = 0 ; i<nums.size() ; i++){
            hashMap[nums[i]]++;
        }

        vector<int> ans;

        for(int i = 0 ; i<k ; i++){

            int max  = maxByValue(hashMap);
            ans.push_back(max);
            hashMap.erase(max);

        }

        return ans;

    }
};