class Solution {
public:
    void sortColors(vector<int>& nums) {
        //brute force
        
        int zeros = 0 ,ones = 0 ,twos = 0;

        int n = nums.size();

        for(int i = 0 ; i<n ; i++){
            if(nums[i] == 0) zeros++;
            if(nums[i] == 1) ones++;
            if(nums[i] == 2) twos++;
        }

        int j = 0;
        while(zeros>0){
            nums[j] = 0;
            zeros--;
            j++;
        }
        while(ones>0){
            nums[j] = 1;
            ones--;
            j++;
        }
        while(twos>0){
            nums[j] = 2;
            twos--;
            j++;
        }
    }
};