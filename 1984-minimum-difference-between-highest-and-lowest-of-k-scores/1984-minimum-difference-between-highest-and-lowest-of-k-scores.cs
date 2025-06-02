public class Solution {
    public int MinimumDifference(int[] nums, int k) {
        int result = 1000009; 
        int n = nums.Length;
        Array.Sort(nums); 
        
        for(int i=0 ;i <= n-k ;i++){
            result = Math.Min(result,nums[i+k-1]-nums[i]);
        }
        return result == 1000009 ? 0 : result;
    }
}