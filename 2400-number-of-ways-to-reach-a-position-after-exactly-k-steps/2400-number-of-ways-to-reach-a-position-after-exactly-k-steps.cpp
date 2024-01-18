class Solution {
 public:
  int numberOfWays(int startPos, int endPos, int k) {
    const int val = k + endPos - startPos;
    if (val < 0 || val & 1)
      return 0;
    const int rightStep = val / 2;
    const int leftStep = k - rightStep;
    if (leftStep < 0)
      return 0;
    return nCk(leftStep + rightStep, min(leftStep, rightStep));
  }

 private:
  int nCk(int n, int k) {
    constexpr int kMod = 1'000'000'007;
    vector<int> dp(k + 1);
    dp[0] = 1;

    while (n-- > 0)  
      for (int j = k; j > 0; --j) {
        dp[j] += dp[j - 1];
        dp[j] %= kMod;
      }

    return dp[k];
  }
};