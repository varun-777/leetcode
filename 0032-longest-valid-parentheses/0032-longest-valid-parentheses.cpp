class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int count = 0,i=0,j=0,len = 0,maxx = 0,maxx1 = 0;
        if(n==0||n==1) return 0;
        while(j<n){
            if(s[j]=='(') count++;
            else count--;
            if(count==0){
                len = j-i+1;
                maxx = max(maxx,len);
            }
            if(count<0){
                count = 0;
                i = j+1;
            }
            j++;
        }
        reverse(s.begin(),s.end());
        i=0,j=0,count = 0,len = 0;
        while(j<n){
            if(s[j]==')') count++;
            else count--;
            if(count==0){
                len = j-i+1;
                maxx1 = max(maxx1,len);
            }
            if(count<0){
                count = 0;
                i = j+1;
            }
            j++;
        }
        return max(maxx,maxx1);
    }
};