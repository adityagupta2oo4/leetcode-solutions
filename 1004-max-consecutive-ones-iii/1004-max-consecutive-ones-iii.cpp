class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int x = 0 , y = 0;

        int count = 0 , sum = 0;
        int tempk = k;

        while(y < nums.size() ){

            if(nums[y] == 1){
                count++;
                y++;
            }
            else if(nums[y] == 0 && tempk > 0 ){
                count++;
                tempk--;
                y++;
            }
            else if(nums[y] == 0 && tempk <= 0){
                tempk = k;
                count = 0;
                x++;
                y = x;
            }

            sum = count>sum ? count : sum;
            
            
        }

        return sum;

    }
};