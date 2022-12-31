# Read input
N, X = map(int, input().split())
portals = {}
for i in range(N):
  a, b = map(int, input().split())
  portals[a] = b
  portals[b] = a

# Calculate number of steps to reach the exit
steps = 0
position = 0
while position != X:
  steps += 1
  position += 1
  if position in portals:
    position = portals[position]

# Print result
print(steps)