class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int start = 0;
        int n = nums.size();
        int end = n-1;

        while(start<=end){

            int mid = start + (end-start)/2;

            if(mid == 0){

                if(n == 1){
                    return nums[0];
                }
                else if(nums[0] != nums[1]){
                    return nums[0];
                }

            }
            else if(mid == n-1){
                if(n == 1){
                    return nums[0];
                }
                else if(nums[n-1] != nums[n-2]){
                    return nums[n-1];
                }
            }
            else if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            else if( nums[mid-1] != nums[mid] ){

                if( mid%2 == 0) start = mid + 1;
                else end = mid -1;
            }
            else if(nums[mid-1] == nums[mid]){
                if( mid%2 == 0) end = end - 1;
                else start = mid +1;
            }
        }
        return 0 ;
    }
};