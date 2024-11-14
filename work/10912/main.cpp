#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hashNumber(int n, int s, int l, vector<vector<vector<int>>> &memo)
{
  if (s == 0 && l == 0)
    return 1;
  if (l <= 0 || s < 0 || n <= 0)
    return 0;
  if (memo[n][s][l] != -1)
    return memo[n][s][l];

  // Si la suma es menor que el límite, no podré cubrirla ya que como mínimo se tiene 1 de valor para las l letras restantes.
  // Por otro lado, si la suma es mayor que el máximo valor que puedo sacar entre las letras que me quedan, la suma no es alcanzable
  if (s < l || s > l * n)
    return 0;

  if (n > s)
  {
    memo[n][s][l] = hashNumber(s, s, l, memo);
  }
  else
  {
    memo[n][s][l] = hashNumber(n - 1, s - n, l - 1, memo) + hashNumber(n - 1, s, l, memo);
  }

  return memo[n][s][l];
}

int main()
{
  int l, s;
  int i = 1;

  vector<vector<vector<int>>> memo(27, vector<vector<int>>(10001, vector<int>(101, -1)));

  cin >> l >> s;
  while (l != 0 && s != 0)
  {
    cout << "Case " << i << ": " << hashNumber(min(s, 26), s, l, memo) << '\n';
    cin >> l >> s;
    i++;
  }

  return 0;
}
