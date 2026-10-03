class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
       int x = 0;
       int ans = 0;
       int zero_count = 0;

       for(int y = 0 ; y<nums.size() ; y++){

            if(nums[y] == 0) zero_count++;

            while(zero_count>k){

                if(nums[x] == 0) zero_count--;
                x++;
            }

            ans = max(ans , y-x+1);
       }

       return ans;
    }
};