class Solution {
public:
    int maxProduct(vector<int>& nums) {
 long long maxEnd = nums[0];
        long long minEnd = nums[0];
        long long ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            long long num = nums[i];

            if(num < 0) {
                swap(maxEnd, minEnd);
            }

            maxEnd = max(num, maxEnd * num);
            minEnd = min(num, minEnd * num);

            ans = max(ans, maxEnd);
        }

        return ans;

    }
};