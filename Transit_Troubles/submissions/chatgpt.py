# Read input
N, w1, w2 = map(int, input().split())
buses = []
for i in range(N):
  a, b = map(int, input().split())
  buses.append((a, b))

# Calculate latest time Bob can leave
time = 0
for a, b in buses:
  time = ((time + a - 1) // a) * a + b
time += w1 + w2

# Print result
print(time)