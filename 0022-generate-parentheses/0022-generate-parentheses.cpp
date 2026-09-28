class Solution {
public:

    void solve(int open,int close,vector<string>&ans,int n,string temp){
        if(open+close==n){
            ans.push_back(temp);
            return;
        }

        if(open<n/2){
            temp+='(';
            solve(open+1,close,ans,n,temp);
            temp.pop_back();
        }
        if(open>close){
            temp+=')';
            solve(open,close+1,ans,n,temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,ans,2*n,"");
        return ans;
    }
};