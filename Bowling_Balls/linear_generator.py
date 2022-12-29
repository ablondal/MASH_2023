import random
pts = []
sz = 100

for x in range(1, sz, 3):
    pts.append((3.14, x))
    pts.append((3.14, -x))

random.shuffle(pts)
print(1, len(pts))
print('\n'.join([' '.join([str(c) for c in pt]) for pt in pts]))
