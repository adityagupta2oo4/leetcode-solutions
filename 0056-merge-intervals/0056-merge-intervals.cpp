class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //step-1 sort the given array

        sort(intervals.begin(),intervals.end());

        // new vector vector

        vector<vector<int>> merged;

        // two pointer approach

        int prev =  0;
        int curr = 1;

        while( curr < intervals.size()){

            int end  = intervals[prev][1];
            int start = intervals[curr][0];

            if(end<start){
                merged.push_back(intervals[prev]);
                prev = curr;
            }
            else{

                // which is greater interval
                intervals[curr][0] = intervals[prev][0];
                intervals[curr][1] = max(intervals[prev][1], intervals[curr][1]);
                prev = curr;
            }

            curr++;

        }
        merged.push_back(intervals[prev]);


        return merged;
    }
};