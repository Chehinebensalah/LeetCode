public class Solution {
    public int MaximumCount(int[] nums) {
        int positive_count = 0; 
        int negative_count = 0;
        foreach(int number in nums){
            positive_count += (number > 0 ? 1 : 0);
            negative_count += (number < 0 ? 1 : 0);
        }
        return Math.Max(positive_count,negative_count);
    }
}