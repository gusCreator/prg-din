denominations = [10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5]
memo = {}

def count_ways(amount, index=0):
  if amount == 0:
    return 1
  # Si el monto es negativo, no se alcanzó una solución
  # Si ya no hay denominaciones para revisar, ya no hay soluciones
  if amount < 0 or index >= len(denominations):
    return 0
  
  if (amount, index) in memo:
    return memo[(amount, index)]

  ways = count_ways(amount - denominations[index], index) + count_ways(amount, index + 1)

  memo[(amount, index)] = ways
  return ways

while True:
  line = input()
  if line.strip() == "0.00":
    break
  amount = int(round(float(line) * 100))
  ways = count_ways(amount)
  print(f"{float(amount) / 100:6.2f}{ways:17d}")
