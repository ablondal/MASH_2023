h = 1000
w = 100

wall = ['+'+('-'*w)+'+']
wall.extend(['|'+('.'*w)+'|' for _ in range(h)])
wall.append('+'+('-'*w)+'+')
wall = [list(w) for w in wall]

from random import randrange
for x in range(1, w+1):
    for y in range(1, h+1):
        a = randrange(100)
        if a < 10:
            wall[y][x] = chr(ord('0')+a)

print(h, w)
print('\n'.join([''.join(w) for w in wall]))