class Solution {
public:
int findLucky(vector<int>& arr) {
    sort(begin(arr), end(arr), greater<int>());
    int cnt = 1;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1])
            ++cnt;
        else {
            if (arr[i - 1] == cnt)
                return cnt;
            cnt = 1;
        }
    }
    return arr.back() == cnt ? cnt : - 1;
}
int main() 
{ 
vector<int> arr = {2,2,3,4}; 
 int ans=findLucky(arr);
 cout<<ans<<endl;
 return 0;
}
        
};