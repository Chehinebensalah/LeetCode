public class Solution {
    private int _check(Dictionary<char, int> d_g , int number){
        Dictionary<char, int> d = new Dictionary<char, int>() ;
        d= d_g;
        string s_number = number.ToString();
        
        Console.WriteLine($"number : "+ s_number );  
        foreach (var item in d)
        {
            Console.WriteLine($"Key: {item.Key}, Value: {item.Value}");
        }

        for(int i=0;i<3;i++){
            if (d.ContainsKey(s_number[i])) {
                if(d[s_number[i]] > 0){
                    d[s_number[i]] -= 1;
                }else if(d[s_number[i]] == 0){
                    d.Remove(s_number[i]);
                }else return 0;
            }
            else
                return 0; 
        }
        // foreach (var item in d)
        // {
        //     Console.WriteLine($"after Key: {item.Key}, Value: {item.Value}");
        // }
        return 1;
    }
    public int[] FindEvenNumbers(int[] digits) {
        Dictionary<char, int> d_g = new Dictionary<char, int>();
        List<int> result = new List<int>();

        for(int i=0;i<digits.Length;i++){
            char c = (char)(digits[i] + '0'); 
            if(d_g.ContainsKey(c)){
                d_g[c]++;
            }else{
               d_g.Add(c,1);
            }
        }

        for(int number = 100 ;number<999 ;number +=2){
            if(_check(d_g ,number) == 1){
                result.Add(number);
            }
        }
        return result.ToArray();
    }
}
/*
0 : 1 
1 : 1
2 : 1
3 : 1
120 

1 
0 : 1 
1 : 0
2 : 1
3 : 1

2
0 : 1 
1 : 0
2 : 0
3 : 1

0
0 : 0 
1 : 0
2 : 0
3 : 1

*/
 