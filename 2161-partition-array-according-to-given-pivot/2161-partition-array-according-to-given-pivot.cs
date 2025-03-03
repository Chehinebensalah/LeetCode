public class Solution {
    public int[] PivotArray(int[] nums, int pivot) {
        List<int> L = new List<int>();
        List<int> R = new List<int>();
        int c = 0; 
        foreach(int element in nums){
            if(element > pivot){
                R.Add(element);
            }else if(element < pivot){
                L.Add(element);
            }else c++;
        }
        List<int> result = new List<int>();
        foreach(int element in L){
            result.Add(element);
        }
        for(int i =0;i<c;i++){
            result.Add(pivot);
        }
        foreach(int element in R){
            result.Add(element);
        }
        return result.ToArray();
    }
}