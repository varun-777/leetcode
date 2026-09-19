class Solution {
public:
    double solve(double x,long long n,double ans){
        if(n==1) return ans;
        if(n%2==0){
           ans = solve(x,n/2,ans*ans);
        }
        else{
            ans = ans*solve(x,(n-1)/2,ans*ans);
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long k = n;
        if(n==0) return 1.0;
        if(k<0){
            return 1/solve(x,-k,x);
        }
        return solve(x,n,x);
    }
};