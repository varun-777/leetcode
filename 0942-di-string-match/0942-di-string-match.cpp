class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(),inc=0,dec = n,flag=1;
        vector<int>ans;
        if(s[0]=='I') ans.push_back((inc++));
        else 
        {
            ans.push_back(n);
            dec--;
            flag = 0;
        }

        for(int i=1;i<n;i++){
            if(s[i]=='I') {
                ans.push_back(inc);
                inc++;
                if(inc > n) inc = 0;
            }
            else{
                ans.push_back(dec);
                dec--;
            }
        }
        if(s[n-1]=='I') ans.push_back(inc);
        else ans.push_back(dec);
        return ans;
    }
};