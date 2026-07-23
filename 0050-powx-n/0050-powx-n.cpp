class Solution {
public:
    double myPow(double x, int n) {
        
        bool negflag = false;
        long m = n;

        if(m<0) m = -1*m, negflag = true;
        if(m== 0 ) return 1;

        double ans = 1;

        while(m>0){

            if(m%2 == 0){
                x *=x;
                m = m/2;
            }
            else{
                ans *=x;
                m--;
            }
        }

        if(m%2 !=0 ) ans = ans*x;

        if(negflag) return 1/ans;

        return ans;
    }
};