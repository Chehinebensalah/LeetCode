public class Solution {
    public int NumEquivDominoPairs(int[][] dominoes) {
        Dictionary<Tuple<int, int>,int> D = new Dictionary<Tuple<int, int>,int>();

        int result = 0 ; 

        for(int i =0;i<dominoes.Length;i++){
            int right = dominoes[i][0] , left = dominoes[i][1];
            if(right>left){
                (right,left) = (left,right);
            }
            Tuple<int,int> current_pair = Tuple.Create(right, left);
            if(D.ContainsKey(current_pair)){
                result += D[current_pair];
                D[current_pair]++;
            }else{
                D[current_pair] = 1;
            }
            
        }
        return result;
    }
}