class Solution {
public:
    long long minn = INT_MAX;

    bool isvalid(string temp,string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                if(temp[i]>temp[i+1]) return false;
            }
            else{
                if(temp[i]<temp[i+1]) return false;
            }
        }
        return true;
    }

    void solve(string s,vector<bool>&vis,string temp){
       if(temp.size()==s.size()+1){
            long long x = stoll(temp);
            if(isvalid(temp,s))
             minn = min(minn,x);
             return;
       }
       if(temp.size()<=s.size()+1){
       for(int i=1;i<=s.size()+1;i++){
            if(!vis[i]){
                vis[i] = true;
                temp+=i+'0';
                solve(s,vis,temp);
                temp.pop_back();
                vis[i] = false;
            }
       }
       }
    }

    string smallestNumber(string s) {
        int n = s.size();
        vector<bool>vis(10,false);
        solve(s,vis,"");
        return to_string(minn);
    }
};