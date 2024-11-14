#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

long long maxHits(int i, int l, const vector<long long> &a, vector<vector<long long>> &m)
{
  if (i >= a.size())
    return 0;

  if (m[i][l] != -1)
    return m[i][l];

  long long t = 0;
  if (a[i] > a[l])
  {
    t = 1 + maxHits(i + 1, i, a, m);
  }
  long long nt = maxHits(i + 1, l, a, m);
  m[i][l] = max(t, nt);
  return m[i][l];
}

void rec(const vector<long long> &a, const vector<vector<long long>> &m)
{
  if (a.size() == 1)
  {
    cout << a[0] << '\n';
    return;
  }
  long long l = 0;
  long long i{0};
  while (i < a.size() - 1)
  {
    if (a[i] > a[l] && m[i][l] == 1 + m[i + 1][i])
    {
      cout << a[i] << '\n';
      l = i;
    }
    ++i;
  }
  if (a[i] > a[l])
    cout << a[i] << '\n';
}

int main()
{
  int n;
  cin >> n;
  cin.ignore().ignore();

  for (int i = 0; i < n; i++)
  {
    string line;
    vector<long long> a;
    a.push_back(-1);
    while (getline(cin, line) && !line.empty())
    {
      long long j;
      istringstream ss(line);
      ss >> j;
      a.push_back(j);
    }

    if (a.size() == 1)
      continue;

    vector<vector<long long>> m(a.size(), vector<long long>(a.size() + 1, -1));
    m[0][0] = -1;
    long long maxLength = maxHits(1, 0, a, m);
    cout << "Max hits: " << maxLength << '\n';

    rec(a, m);
    if (i != n - 1)
      cout << '\n';
  }

  return 0;
}
