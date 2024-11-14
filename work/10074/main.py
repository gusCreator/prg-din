def max_land(x: int, y: int, s: bool, m: list, memo: dict, memoZeros: dict):
  r: int = 0
  if s and x >= 0 and y >= 0:
    for i in range(x, len(m[y])):
      maxArea: int = 0
      if (y, i, s) in memo:
        maxArea = memo[(y, i, s)]
      else:
        minZeros: int = 0
        k = 1
        for j in range(i, len(m[y])):
          zerosC = zeros(j, y, not s, m, memoZeros)
          minZeros = min(minZeros, zerosC) if minZeros != 0 else zerosC
          if minZeros == 0:
            k = 1
          else:
            maxArea = max(maxArea, minZeros * k) 
            k += 1
        memo[(y, i, s)] = maxArea
      r = max(maxArea, r)
    if x == 0:
      r = max(r, max_land(x, y - 1, s, m, memo, memoZeros))
    else:
      r = max(r, max_land(x - 1, y, not s, m, memo, memoZeros))
  elif not s and y >= 0 and x >= 0:
    for i in range(y, len(m)):
      maxArea: int = 0
      if (i, x, s) in memo:
        maxArea = memo[(i, x, s)]
      else:
        minZeros: int = 0
        k = 1
        for j in range(i, len(m)):
          zerosC = zeros(x, j, not s, m, memoZeros)
          minZeros = min(minZeros, zerosC) if minZeros != 0 else zerosC
          if minZeros == 0:
            k = 1
          else:
            maxArea = max(maxArea, minZeros * k)
            k += 1
        memo[(i, x, s)] = maxArea
      r = max(maxArea, r)
    if y == 0:
      r = max(r, max_land(x - 1, y, s, m, memo, memoZeros))
    else:
      r = max(r, max_land(x, y - 1, not s, m, memo, memoZeros))
  return r

def zeros(x: int, y: int, s: bool, m: list, memoZeros: dict):
  if y < 0 or y >= len(m) or x < 0 or x >= len(m[y]):
    return 0
  if m[y][x] == 1:
    return 0
  if (y, x, s) in memoZeros:
    return memoZeros[(y, x, s)]
  if s:
    r = 1 + zeros(x + 1, y, s, m, memoZeros)
  else:
    r = 1 + zeros(x, y + 1, s, m, memoZeros)
  memoZeros[(y, x, s)] = r
  return r
[m, n] = map(int, input().split())
while m != 0 or n != 0:
  l: list = []
  memo = {}
  memoZeros = {}
  for _ in range(m):
    row: list = list(map(int, input().split()))
    l.append(row)
  print(max_land(n - 1, m - 1, True, l, memo, memoZeros))
  [m, n] = map(int, input().split())


