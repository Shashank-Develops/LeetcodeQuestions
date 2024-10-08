class Solution {
 public:
  int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 0;
    int d = 0;  // 0 := north, 1 := east, 2 := south, 3 := west
    int x = 0;  // the start x
    int y = 0;  // the start y
    std::unordered_set<std::pair<int, int>, PairHash> obstaclesSet;

    for (const std::vector<int>& o : obstacles)
      obstaclesSet.insert({o[0], o[1]});

    for (const int c : commands) {
      if (c == -1) {
        d = (d + 1) % 4;
      } else if (c == -2) {
        d = (d + 3) % 4;
      } else {
        for (int step = 0; step < c; ++step) {
          // Replace contains with find
          if (obstaclesSet.find({x + dirs[d][0], y + dirs[d][1]}) != obstaclesSet.end())
            break;
          x += dirs[d][0];
          y += dirs[d][1];
        }
      }
      ans = std::max(ans, x * x + y * y);
    }

    return ans;
  }

 private:
  struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
      return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
  };
};