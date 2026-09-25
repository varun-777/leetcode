class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s) mp[ch]++;
        bool odd = false;
        int ans = 0;
        for(auto it:mp){
            cout<<it.second<<" ";
            if(it.second%2==0) ans+=it.second;
            else{
                odd = true;
                ans+=it.second-1;
            }
        }
        if(odd) return ans+1;
        return ans;
    }
};