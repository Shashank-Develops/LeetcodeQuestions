class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        if(n1 == 0 || n2 == 0)  return "";
        string res(n1+n2, '0');
        int c = 0;
        for(int i = n1-1; i >= 0; i--){
            for(int j = n2-1; j >= 0; j--){
                int tmp = (num1[i]-'0')*(num2[j]-'0')+c+res[i+j+1]-'0';
                res[i+j+1] = tmp%10+'0';
                c = tmp/10;
            }
            res[i] += c;
            c = 0;
        }
        int start = 0;
        while(start < res.length() && res[start] == '0')
            start++;
        if(start == res.length())
            return "0";
        return res.substr(start);
    }
};