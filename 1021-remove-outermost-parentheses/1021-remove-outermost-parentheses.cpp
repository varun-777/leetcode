class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int depth=0;
        for(char ch: s){
            if(ch=='('){
                if(depth>0) res.push_back(ch);
            depth++;
            }
            else{
                depth--;
                if(depth>0) res.push_back(ch);
            }
        }
        return res;
    }
};