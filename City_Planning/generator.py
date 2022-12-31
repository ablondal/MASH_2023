n = 100
from random import randrange, shuffle

edges = set()

# UF = [-1 for _ in range(n+1)]
# def find(x):
#     if UF[x]==-1:
#         return x
#     UF[x] = find(UF[x])
#     return UF[x]

# pts = 100

# while pts > 1:
#     a = randrange(1, n+1)
#     b = randrange(1, n+1)
#     if (a==b) or ((a, b) in edges) or ((b, a) in edges):
#         continue
#     edges.add((a, b))
#     a = find(a)
#     b = find(b)
#     if a != b:
#         UF[a] = b
#         pts-=1

# for _ in range(100):
#     a = randrange(1, n+1)
#     b = randrange(1, n+1)
#     if (a==b) or ((a, b) in edges) or ((b, a) in edges):
#         continue
#     edges.add((a, b))

for i in range(1, n+1):
    for j in range(i+1, n+1):
        edges.add((i, j))

print(n, len(edges))
e = [' '.join([str(a) for a in ed]) for ed in edges]
shuffle(e)
# print(e)
print('\n'.join(e))
