class Solution {
public:

    int factorial(int x){
        
        if(x == 0) return 1;
        return x*factorial(x-1);


    }
    string getPermutation(int n, int k) {


        string ans  = "";

        int temp_n = n;

        int temp_k = k-1;

        vector<int> nums;

        for(int i=1 ; i<=n ; i++){
            nums.push_back(i);
        }

        int fac,index;
        


        while(ans.length() < n){
            

            fac = factorial(--temp_n);


            index = (temp_k)/fac ;
            temp_k %= fac;
            ans += to_string(nums[index]);
            nums.erase(nums.begin()+index);

           
        }


        
        return ans;    
    }
};