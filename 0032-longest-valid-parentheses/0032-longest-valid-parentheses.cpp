class Solution {
public:
int longestValidParentheses(string s) {
        stack<int> list;
        list.push(-1);
        int maxa = 0;
        for(int i=0; i< s.length(); ++i){
            if(s[i] == '('){
                list.push(i);
            }
            else{
                list.pop();
                if(list.empty())
                    list.push(i);
                maxa = max(maxa, i - list.top());
                
            }
        }
        return maxa;
        
    }
};