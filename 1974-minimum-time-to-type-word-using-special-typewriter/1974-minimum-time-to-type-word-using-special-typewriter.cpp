class Solution {
public:
    int minTimeToType(string s) {
        int ans = 0;
        char p = 'a';
        for(int i=0;i<s.size();i++){
            ans+=min(abs(s[i]-p),26-abs(s[i]-p));
            cout<<ans<<" ";
            p = s[i];
        }
        return ans+s.size();
    }
};