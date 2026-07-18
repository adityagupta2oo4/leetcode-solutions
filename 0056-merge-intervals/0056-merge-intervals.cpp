class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //step-1 sort the given array

        sort(intervals.begin(),intervals.end());

        // new vector vector

        vector<vector<int>> merged;

        // optimized version

        for(auto interval : intervals){

            // if mereged array is empty or if current and previous interval doesn't overlap

            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{
                // if overlapping we change the end of last interval in merged

                merged.back()[1] = max(interval[1],merged.back()[1]);

            }

        }
        

        return merged;
    }
};