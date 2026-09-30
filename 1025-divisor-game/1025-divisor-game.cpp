class Solution {
public:

    vector<int> fact(int n){
        vector<int>ans;
        ans.push_back(1);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
        return ans;
    }

    bool divisorGame(int n) {
        vector<bool>dp(n+1,false);
        for(int i=2;i<=n;i++){
            vector<int>factors = fact(i);
            for(auto it:factors){
                if(!dp[i-it]) 
                {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};