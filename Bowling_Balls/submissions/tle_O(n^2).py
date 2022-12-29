r, n = map(int, input().split())
r = float(r)
pts = [tuple(map(float, input().split())) for _ in range(n)]
dists = [
    ((pts[i][0]-pts[j][0])**2 + (pts[i][1]-pts[j][1])**2, i, j)
    for i in range(n) for j in range(i+1, n)
    ]
for d, a, b in dists:
    if abs((d)**0.5 - 2*r) < 5e-3*r:
        print(a+1, b+1)
# d, a, b = min(dists)
# if abs((d)**0.5 - 2*r) < 1e-2*r:
#     print(a+1, b+1)
# else:
#     print(a+1, b+1, abs(d - 4*r*r), d)
#     print(pts[a], pts[b], r)