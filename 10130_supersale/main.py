memo = {}

def ks(objs: list, w: int, index: int):
  if w <= 0 or len(objs) <= index: 
    return 0
  if (w, index) in memo:
    return memo[(w, index)]
  if w < objs[index]["weight"]:
    memo[(w, index)] =  ks(objs, w, index + 1)
  else:
    memo[(w, index)] = max(objs[index]["price"] + ks(objs, w - objs[index]["weight"], index + 1), ks(objs, w, index + 1))
  return memo[(w, index)]


def max_value_family(objs: list, peop: list):                                                   
  optimal_value = 0
  for per in peop:
    optimal_value += ks(objs, per, 0)
  return optimal_value


line = int(input())
while line:
  num_obj = int(input())
  objs = []
  while num_obj:
    obj_arr = input().split(" ")
    objs.append({"price": int(obj_arr[0]), "weight": int(obj_arr[1])})
    num_obj -= 1
  num_pers = int(input())
  pers = []
  while num_pers:
    pers.append(int(input()))
    num_pers -= 1
  print(max_value_family(objs, pers))
  memo = {}
  line -= 1
    
