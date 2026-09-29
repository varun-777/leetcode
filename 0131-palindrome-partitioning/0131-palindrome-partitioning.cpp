class Solution {
public:

    vector<vector<string>>ans;

    bool ispalindrome(string s){
        if(s.size()==0) return false;
        int l = 0 ,r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int idx,string s,int n,vector<string>vec){
        if(idx==n){
            ans.push_back(vec);
            return;
        }

        for(int i=idx;i<n;i++){
            if(ispalindrome(s.substr(idx,(i-idx+1)))){
                vec.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,n,vec);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(0,s,n,{});
        return ans;
    }
};