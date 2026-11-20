class Solution {
public:
    int addDigits(int num) {
        if(num<=9) return num;
        int sum = num,k;
        while(sum>9){
            int temp = sum;
            k = 0;
            while(temp!=0){
                k+=temp%10;
                temp/=10;
            }
            sum = k;
        } 
        return k;
    }
};