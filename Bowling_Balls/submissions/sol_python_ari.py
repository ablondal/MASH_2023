from math import floor
import sys
inp = sys.stdin.read().split()

r, n = map(int, inp[0:2])
r = float(r)
eps = 1e-3

pts = [tuple(map(float, inp[2+2*a:4+2*a])) for a in range(n)]
# print(pts)
dists = []

gridmap = {}
g_sz = 2*r + eps
for j in range(len(pts)):
    x, y = pts[j]
    gx = floor(x/g_sz)
    gy = floor(y/g_sz)
    col1 = [
        (gx+dx, gy+dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1)
        if (gx+dx, gy+dy) in gridmap]
    col2 = [i for g in col1 for i in gridmap[g]]
    for i in col2:
        x2, y2 = pts[i]
        if (x-x2)**2 + (y-y2)**2 <= 4*r*r + eps:
            dists.append( ((x-x2)**2 + (y-y2)**2, i, j))
    if (gx, gy) not in gridmap:
        gridmap[(gx, gy)] = []
    gridmap[(gx, gy)].append(j)

d, a, b = min(dists)
print(a+1, b+1)