class Solution {
public:

    vector<vector<int>>ans;

    void solve(int idx,int n,int k,vector<int>temp,vector<bool>&vis){
        if(idx == k){
            ans.push_back(temp);
            return;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(temp.size()==0){
                    temp.push_back(i);
                    vis[i] = true;
                    solve(idx+1,n,k,temp,vis);
                    vis[i] = false;
                    temp.pop_back();
                }
                else if(temp.size()>0&&temp[temp.size()-1]<i){
                vis[i] = true;
                temp.push_back(i);
                solve(idx+1,n,k,temp,vis);
                temp.pop_back();
                vis[i] = false;
                }
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<bool>vis(n+1,false);
        solve(0,n,k,{},vis);
        return ans;
    }
};