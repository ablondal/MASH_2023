h, w = map(int, input().split())

wall = [list(input()) for _ in range(h+2)]
wall = wall[::-1]
DP = [[1<<24 for _ in range(w+2)] for _ in range(h+2)]
DP[0] = [0 for _ in range(w+2)]

for y in range(1, h+2):
    for x in range(1, w+1):
        cost = 1<<24
        if ord(wall[y][x]) >= ord('0') and ord(wall[y][x]) <= ord('9'):
            cost = int(wall[y][x])
        elif wall[y][x] == '-':
            cost = 0
        else:
            continue
        c2 = 1<<24
        for py in range(max(0, y-5), y):
            for px in range(max(0, x-5), min(w+2, x+6)):
                if (x-px)*(x-px) + (y-py)*(y-py) <= 25:
                    # print('hi')
                    #print(py, px)
                    c2 = min(c2, DP[py][px])
        DP[y][x] = c2 + cost
        # print(DP[y][x])

mc = min(DP[-1][1:-1])
if mc >= 1<<24:
    print(-1)
else:
    print(mc)
