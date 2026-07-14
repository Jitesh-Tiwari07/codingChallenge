class Solution {
public:
    int reverse(int n) {
        int revno=0;
        while(n!=0){
            int ld=n%10;
             
            if(revno>INT_MAX/10 || revno<INT_MIN/10){
                return 0;
            }
            revno=revno*10+ld;
            n/=10;
        }
        return revno;
    }
};