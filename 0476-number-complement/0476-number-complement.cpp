class Solution {
public:
    int findComplement(int num) {
        int n =log2(num); 
        for(int i=n;i>-1;i--){
            num ^=(1<<i);
        }
        return num;
    }
};
