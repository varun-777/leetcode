class Solution {
public:
    int minChanges(string s) {
        vector<string>temp;
        int count = 0;
        int i = 0;
        string k = s;
        while(k.size()!=0){
            // if(i+2<s.size())
            temp.push_back(k.substr(0,2));
            i+=2;
            //if(i+2<=s.size())
            k = s.substr(i,2);
           // else k = "";
        }
        for(string ss:temp){
            cout<<ss<<" ";
            if(ss[0]!=ss[1]) count++;
        }
        return count;
    }
};