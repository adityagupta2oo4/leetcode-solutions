class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        //step 1  sort both

        sort(g.rbegin() , g.rend());
        sort(s.rbegin() ,s.rend());

        int greed = 0;
        int  size = 0;

        int count = 0;
        while(greed < g.size() && size<s.size()){

            if(s[size] >= g[greed]){

                count++;
                size++;
                greed++;
            }
            else{
                greed++;
            }
        } 

        return count;


    }
};