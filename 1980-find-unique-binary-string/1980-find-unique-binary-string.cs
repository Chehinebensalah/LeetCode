public class Solution {
    
    List<string> l = new List<string>{"1","0"};
    string res = new string("");
    Dictionary<string,bool> visited = new Dictionary<string,bool>();

    void construct(int n ,string[] nums){
        Queue<string> q = new Queue<string>();
        foreach(string s in l){
            q.Enqueue(s);
        }
        string a = q.Peek();
        while(q.Count>0){
            q.Dequeue();
            foreach(string s in l){
                if((a+s).Length == n && !visited.TryGetValue(a+s, out bool value)){
                    res = (a+s);
                    return; 
                }
                Console.WriteLine(a+s);
                q.Enqueue(a+s);
            }
            a = q.Peek();
        }

    }

    public string FindDifferentBinaryString(string[] nums) {
        foreach(string n in nums){
            visited.Add(n,true);
        }
        int _size = nums[0].Length;
        if(_size == 1){
            if(nums[0] == "1")
                return "0";
            else 
                return "1";
        }
        construct(_size,nums);
        return res;
    }
}
