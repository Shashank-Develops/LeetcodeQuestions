class Solution {
public:
    int fib(int N) {
        if(N < 2){
            return N;
        }
        vector vals = {0, 1};
        
        int i = 2;
        int sum = 1;
        while(i <= N){
            sum = vals[i-1] + vals[i-2];
            vals.push_back(sum);
            i++;
        }
        
        return sum;
    }
};