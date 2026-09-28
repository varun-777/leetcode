class Solution {
public:

    unordered_map<int,string>mp;

    void start(){
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
    }

    void solve(int idx,string digits,vector<string>&ans,string temp,int n){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(auto ch:mp[digits[idx]-'0']){
            temp+=ch;
            solve(idx+1,digits,ans,temp,n);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string>ans;
        start();
        solve(0,digits,ans,"",n);
        return ans;
    }
};