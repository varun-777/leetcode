class Solution {
public:
    int maxDepth(string s) {
        int maxx = INT_MIN,ans = 0;
        for(char ch:s){
            if(ch == '(') ans++;
            else if(ch==')') ans--;
            maxx = max(ans,maxx);
        }
        return maxx;
    }
};