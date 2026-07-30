class Solution {
public:

    void merge(vector<int> &nums,int low , int mid , int high){


        int left = low;
        int right = mid+1;
        vector<int> temp;
        while(left<= mid &&  right<=high){
            if(nums[left]<=nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while(left<= mid) temp.push_back(nums[left++]);
        while(right<= high) temp.push_back(nums[right++]);

        for(int i = low ; i<=high ; i++) nums[i] = temp[i-low];


    }

    int count_pair(vector<int> &nums , int low , int mid , int high){

        int count = 0;
        int j = mid+1;
        for(int i=low ; i<=mid ; i++){
            while( j <= high && nums[i] > nums[j]*2LL) j++;
            count += j - (mid+1);
        }
        return count;
    }

    int merge_sort_count(vector<int> &nums , int low, int high){

        //stop case of recurcion
        int cnt = 0;
        if(low>=high) return 0;

        int mid = low + (high-low)/2;

        cnt += merge_sort_count(nums,low,mid);
        cnt += merge_sort_count(nums,mid+1,high);
        cnt += count_pair(nums,low,mid,high);

        merge(nums,low,mid,high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        int ans = merge_sort_count(nums,0,nums.size()-1);

        return ans;
        
        
    }
};