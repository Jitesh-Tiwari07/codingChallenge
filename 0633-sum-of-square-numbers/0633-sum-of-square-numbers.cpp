class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a= 0,b=sqrt(c);
        while(a<=b){
            long long temp = (a*a)+(b*b);
            if(temp==c){
                return true;
            }
            else if(temp>c){
                b--;
            }
            else{
                a++;
            }
        }
        return false;
    }
};