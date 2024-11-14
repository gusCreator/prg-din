# S

f(n, i), n pertenece a los R y n >= 0, i pertenece Z -> [0, 10]

# R

f(n, i) = f(n - denominaciones[i], i) + f(n, i + 1)

# T

n, 0 -> n - d[0], 0 ... 0, i
     -> n, 1        ... n < 0, i
                    ... n, i > 10

# B

n == 0 -> 1
n < 0 or i > 10 -> 0

# O

Pseudocodigo

# T

O(n * i)?
