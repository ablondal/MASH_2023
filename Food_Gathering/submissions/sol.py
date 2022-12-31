n, k = map(int, input().split())

G = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b, d = map(int, input().split())
    G[a].append((b, d))
    G[b].append((a, d))

fd = set(map(int, input().split()))

tot = 0

def findfood(curr, prev=-1):
    global tot
    hasfood = curr in fd
    for next, dist in G[curr]:
        if next == prev:
            continue
        next_has_food = findfood(next, curr)
        if next_has_food:
            tot += 2*dist
        hasfood = hasfood or next_has_food
    return hasfood

findfood(1)

print(tot)