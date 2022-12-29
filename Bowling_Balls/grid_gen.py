import random
from math import cos, sin, pi
pts = []
r = 33
sz = 316
gap = 0.1

for x in range(0, sz):
    for y in range(0, sz):
        pts.append(( (x+y/2)*(2*r+gap), y*(2*r+gap)*0.9))

shift = (2*r*cos(pi/3), 2*r*sin(pi/3))
npt = pts[len(pts)//2 + 3]
nwpt = (npt[0]+shift[0], npt[1]+shift[1])

pts2 = [pt for pt in pts if (pt[0]-nwpt[0])**2+(pt[1]-nwpt[1])**2 >= (4*r*r-1e-3) ]
# print(len(pts2))
pts2.append(nwpt)

random.shuffle(pts2)
# x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)
a = 0.2
pts2 = [(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)) for x,y in pts2]

print(r, len(pts2))
print('\n'.join(["{:.6f} {:.6f}".format(*pt) for pt in pts2]))
