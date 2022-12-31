# Read input
N, K = map(int, input().split())
cards = list(map(int, input().split()))

# Sort cards in decreasing order
cards.sort(reverse=True)

# Calculate Bob's guaranteed points
points = 0
for i in range(K):
  points += (cards[i] - cards[K + i]) ** 2

# Print result
print(points)