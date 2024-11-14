def f(n: int, s: int, l: int, memo: list):
  if l < 0 or s < 0 or n > 27:
    return 0
  if s == 0 and l == 0:
    return 1
  # No lo tomo / Lo tomo
  if (n, s, l) in memo:
    return memo[(n, s, l)]
  if n > s:
    memo[(n, s, l)] = f(n + 1, s - n, l - 1, memo)
  else:
    memo[(n, s, l)] = f(n + 1, s, l, memo) + f(n + 1, s - n, l - 1, memo)
  return memo[(n, s, l)]

l: int = 0
s: int = 0
[l, s] = map(int,input().split())
i: int = 1
while l and s:
  memo = {}
  print(f'Case {i}: {f(1, s, l, memo)}')
  [l, s] = map(int,input().split())
  i += 1
  