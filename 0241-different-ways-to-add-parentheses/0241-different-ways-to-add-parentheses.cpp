class Solution {
public:
 
 int perform(int x,int y,char ch){
    switch(ch){
        case '+':return x+y; break;
        case '-': return x-y; break;
        case '*': return x*y; break;
    }
    return 0;
 }

    vector<int> solve(string s){
        bool isnumber = 1;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i])){
                isnumber = 0;
                 string leftpart = s.substr(0,i);
                 string rightpart = s.substr(i+1);
                 vector<int>left = solve(leftpart);
                 vector<int>right = solve(rightpart);

                 for(auto x:left){
                    for(auto y:right){
                        int k = perform(x,y,s[i]);
                        ans.push_back(k);
                    }
                 }

            }
        }
        if(isnumber) ans.push_back(stoi(s));
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return  solve(expression);
    }
};