class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,int k,int target,vector<int>temp,vector<bool>&vis){
        if(temp.size()==k){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=idx;i<=9;i++){
            if(!vis[i]){
                vis[i] = true;
                temp.push_back(i);
                target-=i;
                solve(i+1,k,target,temp,vis);
                temp.pop_back();
                target+=i;
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool>vis(10,false);
        solve(1,k,n,{},vis);
        return ans;
    }
};