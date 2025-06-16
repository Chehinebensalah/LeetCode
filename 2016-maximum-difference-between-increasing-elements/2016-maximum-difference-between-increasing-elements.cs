public class Solution {
    public int MaximumDifference(int[] nums) {
        int n = nums.Length;
        int result = -1;
        for(int i=0; i<n ;i++){
            for(int j=i; j<n ;j++){
                if(i!=j && nums[j]>nums[i]){
                    result = Math.Max(result,nums[j]-nums[i]);
                }
            }
        }
        return result;
    }
}