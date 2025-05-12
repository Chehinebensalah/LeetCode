public class Solution {
    public bool check(int[] arr , int i ){
        return arr[i]% 2 == 1 
            && arr[i+1]% 2 == 1 
            && arr[i+2]% 2 == 1 ;
    }
    public bool ThreeConsecutiveOdds(int[] arr ) {
        int n = arr.Length ; 
        if(n < 3 ) return false;
        for(int i = 0 ; i < n-2 ; i++ ){
            if(check(arr,i))
                return true;
        }
        return false;
    }
}
