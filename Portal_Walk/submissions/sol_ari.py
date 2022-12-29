n, x = map(int, input().split())
G = {}
for _ in range(n):
    a, b = map(int, input().split())
    G[a] = b
    G[b] = a

pos = 0
t = 0
while pos != x:
    pos += 1
    t += 1
    if pos in G:
        pos = G[pos]

print(t)