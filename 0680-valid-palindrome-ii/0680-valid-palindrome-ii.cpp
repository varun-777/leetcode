class Solution {
public:
    bool Ans1(string s){
        int l=0,r=s.size()-1,c=0;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else if(s[r-1]==s[l]){
                r-=2;
                l++;
                c++;
            }
            else if(s[l+1]==s[r]){
                l+=2;
                r--;
                c++;
            }
            
            else return false;
            if(c>1) return false;
        }
        return true;
    }
    bool Ans2(string s){
        int l=0,r=s.size()-1,c=0;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else if(s[l+1]==s[r]){
                l+=2;
                r--;
                c++;
            }
            else if(s[r-1]==s[l]){
                r-=2;
                l++;
                c++;
            }
            else return false;
            if(c>1) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return Ans1(s)|Ans2(s);
    }
};