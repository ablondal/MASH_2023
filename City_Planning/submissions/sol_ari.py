n, m = map(int, input().split())

# Create the graph of the city as an adjacency list
G = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

# We need to check if there are bridges in the graph
visited = set()
timein = [-1 for _ in range(n+1)]
lo = [-1 for _ in range(n+1)]
timer = 0

bridges = []

import sys
sys.setrecursionlimit(1000000)

def isbridge(curr, prev=-1):
    global timer
    visited.add(curr)
    timein[curr] = timer
    lo[curr] = timer
    timer += 1
    for next in G[curr]:
        if next == prev:
            continue
        if next in visited:
            lo[curr] = min(lo[curr], timein[next])
        else:
            isbridge(next, curr)
            lo[curr] = min(lo[curr], lo[next])
            # print(lo[next], timein[curr])
            if lo[next] > timein[curr]:
                bridges.append((curr, next))

isbridge(1, -1)

# print(len(bridges))
# print('\n'.join([' '.join(map(str, b)) for b in bridges]))

if len(bridges) > 0:
    print("NO")
else:
    print("YES")