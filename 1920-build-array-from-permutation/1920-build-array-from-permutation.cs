public class Solution {
    public int[] BuildArray(int[] nums) {
        int n = nums.Length ; 
        int[] resultArray = new int[n]; 
        for(int i=0 ;i<n ;i++){
            resultArray[i] = nums[nums[i]];
        }
        return resultArray;
    }
}