#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>

using namespace std;

struct MemoKey
{
  int x, y, minZ;
  bool s;
  bool operator==(const MemoKey &o) const
  {
    return tie(x, y, s) == tie(o.x, o.y, o.s);
  }
};

struct MemoKeyHash
{
  size_t operator()(const MemoKey &key) const
  {
    return hash<int>()(key.x) ^ hash<int>()(key.y) ^ hash<int>()(key.minZ) ^ hash<bool>()(key.s);
  }
};

int zeros(int x, int y, bool s,
          const vector<vector<int>> &m,
          unordered_map<MemoKey, int, MemoKeyHash> &mZ)
{
  if (y >= m.size() || x >= m[y].size())
    return 0;
  if (m[y][x] == 1)
    return 0;

  MemoKey key = {x, y, s};
  if (mZ.find(key) != mZ.end())
  {
    return mZ[key];
  }

  int result;
  if (s)
  {
    result = 1 + zeros(x + 1, y, s, m, mZ);
  }
  else
  {
    result = 1 + zeros(x, y + 1, s, m, mZ);
  }
  mZ[key] = result;
  return result;
}

int maxArea(int x, int y, bool s,
            int k, int minZeros,
            const vector<vector<int>> &m,
            unordered_map<MemoKey, int, MemoKeyHash> &memo)
{
  if (y >= m.size() || x >= m[y].size())
    return 0;
  unordered_map<MemoKey, int, MemoKeyHash> mZ;
  int zerosC = zeros(x, y, !s, m, mZ);
  int minZ = (minZeros != 0)
                 ? min(minZeros, zerosC)
                 : zerosC;
  MemoKey key = {x, y, minZ, s};
  if (memo.find(key) != memo.end())
  {
    return memo[key];
  }
  int maxA = 0;
  if (minZ == 0)
  {
    maxA = maxArea((s ? x + 1 : x),
                   (s ? y : y + 1), s, 1, minZ, m, memo);
  }
  else
  {
    maxA = max(minZ * k, maxArea((s ? x + 1 : x),
                                 (s ? y : y + 1), s, k + 1, minZ, m, memo));
  }
  memo[key] = maxA;
  return maxA;
}

int max_land(int x, int y, bool s,
             const vector<vector<int>> &m)
{
  int r = 0;
  unordered_map<MemoKey, int, MemoKeyHash> memo;

  if (s && x >= 0 && y >= 0)
  {
    for (int i = x; i < m[y].size(); ++i)
    {
      r = max(r, maxArea(i, y, s, 1, 0, m, memo));
    }
    if (x == 0)
    {
      r = max(r, max_land(x, y - 1, s, m));
    }
    else
    {
      r = max(r, max_land(x - 1, y, !s, m));
    }
  }
  else if (!s && y >= 0 && x >= 0)
  {
    for (int i = y; i < m.size(); ++i)
    {
      r = max(r, maxArea(x, i, s, 1, 0, m, memo));
    }
    if (y == 0)
    {
      r = max(r, max_land(x - 1, y, s, m));
    }
    else
    {
      r = max(r, max_land(x, y - 1, !s, m));
    }
  }
  return r;
}
int main()
{
  int m, n;
  cin >> m >> n;
  while (m != 0 || n != 0)
  {
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        cin >> grid[i][j];
      }
    }

    cout << max_land(n - 1, m - 1, true, grid) << '\n';
    cin >> m >> n;
  }
  return 0;
}