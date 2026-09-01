class Solution {
public:
    int trap(vector<int>& height) {

        int left =  0;
        int right = height.size()-1;

        int lmax = height[left];
        int rmax = height[right];

        int water = 0;

        //starting the loop
        while(left<right){


            if(height[left]<height[right]){
                
                lmax = (int)max(lmax,height[left]);
                water += lmax - height[left];
                left++;

            }
            else{
                rmax = (int)max(rmax,height[right]);
                water += rmax - height[right];
                right--;
            }
        }

        return water;

        
    }
};