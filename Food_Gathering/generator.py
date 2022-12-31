n = 1000
k = 1000
md = 100000
from random import shuffle, randrange, choice, sample

col = set([1])
edges = []

while len(col) < n:
    b = randrange(2, n+1)
    if b in col:
        continue
    a = choice(list(col))
    d = randrange(1, md)
    col.add(b)
    edges.append(f'{a} {b} {d}')

food = ' '.join([str(f) for f in sample(col, k)])
shuffle(edges)

print(n, k)
print('\n'.join(edges))
print(food)


