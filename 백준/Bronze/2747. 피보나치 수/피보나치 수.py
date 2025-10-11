def fibonacci(n):
  if n == 0:
    p[0] = 0
    return 0
  if n == 1:
    p[1] = 1
    return 1
  if p[n] == 0:
    p[n] = fibonacci(n-1) + fibonacci(n-2)
  return p[n]
  
p = [0] * 46
print(fibonacci(int(input())))