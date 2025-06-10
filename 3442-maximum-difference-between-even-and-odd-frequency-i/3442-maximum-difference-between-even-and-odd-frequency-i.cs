public class Solution {
    public int MaxDifference(string s) {
        int[] char_count = new int[26];
        Array.Fill(char_count,0);
        foreach(char c in s){
            char_count[c-'a']++;
        }
        int max_odd = int.MinValue, min_even = int.MaxValue;
        
        foreach(int number in char_count){
            if(number%2==1){
                max_odd = Math.Max(max_odd,number);
            }
            if(number%2==0 && number !=0 ){
                min_even = Math.Min(min_even,number);
            }
        }

        return max_odd - min_even ;
    }
}