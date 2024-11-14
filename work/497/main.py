def f(i: int, v: int, a: list, m: dict):
  if i >= len(a):
    return [0]
  if (i, v) in m:
    return m[(i, v)]
  nt = f(i + 1, v, a, m)
  if (a[i] > v):
    t = f(i + 1, a[i], a, m)
    t = t.copy()
    t[0] += 1
    t.append(a[i])
    if t[0] >= nt[0]:
      m[(i ,v)] = t
      return t
  m[(i ,v)] = nt
  return nt

n: int = int(input())
input()
for i in range(n):
  j = input()
  a = []
  while j:
    a.append(int(j))
    j = input()
  m = {}
  r = f(0, -1, a, m)
  print(f'Max hits: {r[0]}')
  for k in range(len(r) - 1,0,-1):
    print(r[k])
